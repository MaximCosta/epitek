bash = {
    next: { h: 1, m: 0, s: 3 },
    bot: document.getElementById("bottoms"),
    tag: document.getElementById("prompts"),
    com: () => document.getElementById("command"),
    break: () => document.createElement("br"),
    intro: [
        " _______  _______ _________   _________ _______ ",
        "(  ____ \\(  ____ )\\__   __/   \\__   __/(  ____ )",
        "| (    \\/| (    )|   ) (         ) (   | (    )|",
        "| (__    | (____)|   | |  _____  | |   | (____)|",
        "|  __)   |  _____)   | | (_____) | |   |  _____)",
        "| (      | (         | |         | |   | (      ",
        "| (____/\\| )      ___) (___      | |   | )      ",
        "(_______/|/       \\_______/      )_(   |/       ",
    ],
    user: "user",
    host: "epi-tp",
    in_exec: false,
    clos: () => `:${bash.path === "/" ? "~" : bash.path}$`,
    venv: "",
    auto: false,
    iauto: 0,
    cauto: 0,
    func: {
        rand: (_i, _a) => Math.floor(Math.random() * (_a - _i + 1)) + _i,
        sleep: (_) => new Promise((resolve) => setTimeout(resolve, _)),
        text_color: (_, __) => `<span style="color:${__}">${_}</span>`,
        sp_path: (_) => (_ ? (_[0] != "/" ? `${bash.path}/${_}` : _) : bash.path).split("/").filter((f) => f),
        gh_path: (_) => (_ ? (_[0] != "/" ? `${bash.gh_path}/${_}` : _) : bash.gh_path).split("/").filter((f) => f),
        valid_url: (_) => !!new RegExp("^(https?:\\/\\/)?((([a-z\\d]([a-z\\d-]*[a-z\\d])*)\\.)+[a-z]{2,}|((\\d{1,3}\\.){3}\\d{1,3}))(\\:\\d+)?(\\/[-a-z\\d%_.~+]*)*(\\?[;&a-z\\d%_.~+=-]*)?(\\#[-a-z\\d_]*)?$", "i").test(_),
        get_path: (_ = []) => {
            if (typeof _ === "object") _ = _[1];
            let path = bash.directory.dir;
            let cpath = bash.func.sp_path(_);
            if (cpath.length) {
                for (const p of cpath) {
                    if (p == "..") path = path[".."]();
                    else if (p == ".") path = path["."]();
                    else if (path[p]?.type === 0)
                        return {
                            error: {
                                code: 1,
                                name: "current path is not valid",
                                cd: "cd_not_dir",
                                cat: "cat_is_dir",
                            },
                        };
                    else path = path[p]?.dir;
                }
            }
            if (!path)
                return {
                    error: {
                        code: 1,
                        name: "current path is not valid",
                        cd: "cd_not_found",
                        cat: "cat_not_found",
                    },
                };
            return path;
        },
        cd: (move) => {
            let cur = bash.path;
            if (!move[1] || move[1] === "/") {
                bash.path = "/";
                return [false, 0, 0];
            }
            let path = bash.func.sp_path(move[1]);
            if (move[1]) {
                bash.path = "/" + path.join("/");
                let data = bash.func.get_path();
                if (data?.error?.code == 1) {
                    bash.path = cur;
                    return [bash.errors[data.error.cd](move[1]), 0, 1];
                }
                bash.func.fix_path();
                bash.func.fix_path_gh();
                return [false, 0, 0];
            }
            return [bash.errors.cd_not_found(move[1] || ""), 0, 1];
        },
        ls: (_) => {
            let a = bash.func.get_path(_);
            let b = Object.values(a)
                .sort((a, b) => (a.name > b.name ? 1 : b.name > a.name ? -1 : 0))
                .map((f) => (f?.type || [".", ".."].includes(f.name) ? bash.func.text_color(f.name + "/", bash.color.blue) : f.name)) //  + (f.type === 1 ? "/" : "")
                .join(" ");
            return [b, 0, b?.error?.code == 1];
        },
        mkdir: (_) => {
            if (!_[1]) return [bash.errors.mkdir_miss(), 0, 1];
            let a = bash.func.sp_path(_[1]);
            let b = a.pop();
            let c = bash.func.get_path(`/${a.join("/")}`);
            if (c?.error?.code == 1) return [bash.errors.mkdir_not_dir(_[1]), 0, 1];
            if (c[b]?.name) return [bash.errors.mkdir_exists(_[1]), 0, 1];
            c[b] = {
                type: 1,
                name: b,
                dir: {
                    "..": () => bash.func.get_path(`/${a.join("/")}`),
                    ".": () => bash.func.get_path(`/${a.join("/")}/${b}`),
                },
                last_update: new Date().getTime(),
            };
            return [false, 0, 0];
        },
        clear: (_) => {
            prompts.innerHTML = '<span id="command" contenteditable="true" class="single-line"  autofocus><span>';
            init_prompt();
            return ["", 0, 0];
        },
        fix_path: (_) => {
            let a = bash.func.sp_path().filter((f) => f && f != ".");
            let continuer = true;
            while (continuer) {
                continuer = false;
                for (let i = 0; i < a.length; i++) {
                    if (a[i] && a[i] != ".." && a[i + 1] == "..") {
                        a[i] = "";
                        a[i + 1] = "";
                        continuer = true;
                    }
                }
                a = a.filter((f) => f);
            }
            bash.path = "/" + a.filter((f) => f && f != "..").join("/");
        },
        fix_path_gh: (_) => {
            let a;
            if (_) a = _.filter((f) => f && f != ".");
            else a = bash.func.gh_path().filter((f) => f && f != ".");
            let continuer = true;
            while (continuer) {
                continuer = false;
                for (let i = 0; i < a.length; i++) {
                    if (a[i] && a[i] != ".." && a[i + 1] == "..") {
                        a[i] = "";
                        a[i + 1] = "";
                        continuer = true;
                    }
                }
                a = a.filter((f) => f);
            }
            if (_) return a.filter((f) => f && f != "..");
            else bash.gh_path = "/" + a.filter((f) => f && f != "..").join("/");
        },
        cat: (_) => {
            let param = { e: 0 };
            if (_.includes("-e")) param.e = 1;
            _ = bash.func.sp_path(_.filter((f) => f && f[0] != "-" && f != "cat")[0]);
            let path = `/${_.join("/")}`;
            let file = _.pop();
            let dir = bash.func.get_path(`/${_.join("/")}`);
            if (dir?.error?.code == 1) return [bash.errors[dir.error.cat](path), 0, 1];
            if (!dir[file]) return [bash.errors.cat_not_found(path), 0, 1];
            if (dir[file].type === 1) return [bash.errors.cat_is_dir(path), 0, 1];
            let content = dir[file].content;
            if (param.e) content = content.replaceAll("\n", "$\n");
            return [content, 0, 0];
        },
        gh_repos: async (_) => {
            let path = bash.func.gh_path(_.slice(1));
            path = bash.func.fix_path_gh(path);
            let id = new Date().getTime().toString();
            bash.com().textContent = "";
            aElt("span", ".", bash.color.yellow, "load", id);
            let repo2 = path.length >= 2 ? "/" + path.slice(1).join("/") : "";
            let url = `https://api.github.com/${!path.length ? "orgs" : "repos"}/EPI-TP/${!path.length ? "repos" : path[0] + "/contents"}${repo2}`;
            let request = await fetch(url);
            let data = await request.json();
            document.getElementById(id)?.remove();
            if (!request || request.status != 200) return [`${bash.errors.github_req("ls")}\n${data?.message || "Erreur (wrong link, no connection, ...)."}`, 0, 1];
            let repos = data.map((f) => (f?.type == "dir" ? bash.func.text_color(f.name + "/", bash.color.blue) : f.name));
            return [repos.join(" "), 0, 0];
        },
        gh_cd: async (_) => {
            let path = bash.func.gh_path(_.slice(1));
            path = bash.func.fix_path_gh(path);
            let id = new Date().getTime().toString();
            bash.com().textContent = "";
            aElt("span", ".", bash.color.yellow, "load", id);
            let repo2 = path.length >= 2 ? "/" + path.slice(1).join("/") : "";
            let url = `https://api.github.com/${!path.length ? "orgs" : "repos"}/EPI-TP/${!path.length ? "repos" : path[0] + "/contents"}${repo2}`;
            let request = await fetch(url);
            let data = await request.json();
            document.getElementById(id)?.remove();
            if (!request || request.status != 200) return [`${bash.errors.github_req("cd")}\n${data?.message || "Erreur (wrong link, no connection, ...)."}`, 0, 1];
            if (Array.isArray(data)) {
                bash.gh_path = `/${path.join("/")}`;
                return [false, 0, 0];
            }
            return [bash.errors.cd_not_dir(`/${_.slice(1).join("/")}`), 0, 1];
        },
        gh_cat: async (_) => {
            let path = bash.func.gh_path(_.slice(1));
            let id = new Date().getTime().toString();
            bash.com().textContent = "";
            aElt("span", ".", bash.color.yellow, "load", id);
            let repo2 = path.length >= 2 ? "/" + path.slice(1).join("/") : "";
            let url = `https://api.github.com/${!path.length ? "orgs" : "repos"}/EPI-TP/${!path.length ? "repos" : path[0] + "/contents"}${repo2}`;
            let request = await fetch(url);
            let data = await request.json();
            document.getElementById(id)?.remove();
            if (!request || request.status != 200) return [`${bash.errors.github_req("cat   ")}\n${data?.message || "Erreur (wrong link, no connection, ...)."}`, 0, 1];
            if (Array.isArray(data)) return [bash.errors.cat_is_dir(`/${_.slice(1).join("/")}`), 0, 1];
            return [`<pre><code>${atob(data.content)}</code></pre>`, 1, 0];
        },
        github: (_) => {
            bash.venv = "git";
            return ["github mode enable ...\nTape ‘bye’, to exit github mode.", 0, 0];
        },
        bye: (_) => {
            bash.venv = "";
            return ["github mode disable ...\nTape ‘github’, to enable github mode.", 0, 0];
        },
        nano: async (_) => {
            // let id = new Date().getTime().toString();
            // bash.com().textContent = "";
            // let pre = document.createElement("div");
            // pre.setAttribute("contenteditable", true);
            // pre.classList.add("nano");
            // pre.id = id;
            // bash.tag.insertBefore(pre, bash.com());
            // hljs.highlightElement(pre);
            // await bash.func.sleep(1000000);
            return ["build later", 0, 0];
        },
        curl: async (_, __, _p) => {
            let link = { "--data": "-d" };
            let id = new Date().getTime().toString();
            bash.com().textContent = "";
            aElt("span", ".", bash.color.yellow, "load", id);
            console.log({ _, __, _p });
            document.getElementById(id)?.remove();
            return [false, 0, 0];
        },
        bark: (_) => {
            let [__, _t] = [Math.max(1, parseInt(_[1]) || 1), Math.max(1, parseInt(_[2] || 100))];
            (async (__, _t) => {
                for (let i = 0; i < __; i++) {
                    new Audio("assets/sounds/bark.mp3").play();
                    await bash.func.sleep(_t);
                }
            })(__, _t);
            return [false, 1, 0];
        },
        drag_test: (_, __, _p) => {
            let id = new Date().getTime().toString().slice(-6);
            let template = document.importNode(document.querySelector("#tmp_windows").content, true);
            let gui_app = document.createElement("div");
            let tooltip = document.createElement("div");

            gui_app.appendChild(template);
            gui_app.id = id;
            gui_app.querySelector(".windows_title").textContent = _p.get("Title", "--title", "-t");
            gui_app.querySelector(".windows_iframe").src = _p.get("/games/lsd/index.html", "--content", "-c");
            gui_app.querySelector(".windows_iframe").id = id + "_iframe";
            gui_app.querySelector(".windows_iframe").addEventListener("load", (e) => set_privew(document.querySelector(`[id="${id}_tooltip"]`)));
            gui_app.classList.add("dragable", "drag_test");
            gui_app.style.left = bash.func.rand(100, 250) + "px";
            gui_app.style.top = bash.func.rand(100, 250) + "px";

            tooltip.id = id + "_tooltip";
            tooltip.classList.add("tooltiptext");
            tooltip.innerHTML = _p.get("Title", "--title", "-t");
            tooltip.onmouseover = set_privew;
            tooltip.appendChild(document.createElement("canvas"));
            tooltip.onmousedown = (e) => {
                let ifr = document.querySelector(`[id="${id}"]`);
                ifr.style.visibility = "visible";
                ifr.style["z-index"] = get_max_index() + 1;
            };

            let app_name = _p.get("App", "--app", "-a")[0];
            let icon_app = document.querySelector(`[id="${app_name}"]`);
            if (!icon_app) {
                icon_app = document.createElement("div");
                icon_app.id = _p.get("App", "--app", "-a")[0];
                icon_app.classList.add("db_item");
                icon_app.textContent = _p.get("App", "--app", "-a")[0].slice(0, 2);
                tool_group = document.createElement("div");
                tool_group.classList.add("tool_group");
                icon_app.appendChild(tool_group);
                document.querySelector("#dock_bar").appendChild(icon_app);
            }
            icon_app.querySelector(".tool_group").appendChild(tooltip);
            document.body.appendChild(gui_app);
            dragElement(gui_app);
            return ["window launch", 0, 0];
        },
        max_field_len: (_, _f) => {
            return _.reduce((max, obj) => (max[_f].toString().length > obj[_f].toString().length ? max : obj))[_f].toString().length || 1;
        },
        ps: (_) => {
            let app = [{ id: "id", title: "name", content: "link", open: "status" }];
            document.querySelectorAll(".dragable").forEach((e) =>
                app.push({
                    id: e.id,
                    title: e.querySelector(".windows_title").textContent,
                    content: e.querySelector(".windows_iframe").src.replace(document.location.origin, ""),
                    open: e.style.display == "none" ? "reduce" : "open",
                })
            );
            let str = [];
            for (let i = 0; i < app.length; i++) {
                let id = app[i].id.padStart(bash.func.max_field_len(app, "id"));
                let title = app[i].title.padStart(bash.func.max_field_len(app, "title"));
                let content = app[i].content.padStart(bash.func.max_field_len(app, "content"));
                let open = app[i].open.padStart(bash.func.max_field_len(app, "open"));
                str.push(`${id} ${title} ${content} ${open}`);
            }
            return [str.join("\n"), 0, 0];
        },
        kill: (_) => {
            let id = _[1];
            if (!isNaN(id)) [bash.errors.kill_param_not(id), 0, 1];
            id = parseInt(id);
            let process = document.querySelectorAll(`[id="${id}"]`);
            if (!process.length) [bash.errors.kill_not_found(id), 0, 1];
            process.forEach((e) => e.remove());
            return [`process: ${id}: killed`, 0, 0];
        },
        check_url: (_) => {
            var xhr = new XMLHttpRequest();
            xhr.open("HEAD", _, false);
            xhr.send();
            return xhr.status !== 404;
        },
        gui: (_, __) => {
            if (!_[1]) return [bash.errors.gui_no_param(), 0, 1];
            let link = `/games/${_[1]}/index.html`;
            if (!bash.func.check_url(link)) return [bash.errors.gui_not_found(_[1]), 0, 1];
            return bash.func.drag_test(_, __, { "--title": _[1], "--content": link });
        },
        echo: (_) => {
            return [_[1], 0, 0];
        }
    },
    command: {
        history: (_) => [bash.history.map((_, i) => `${i.toString().padStart(bash.history.length.toString().length, " ")}  ${_}`).join("\n"), 0, 0],
        next_event_time: (_) => [`<span class='th'>${bash.next.h}</span>h <span class='tm'>${bash.next.m}</span>m <span class='ts'>${bash.next.s}</span>s`, 0, 0],
        game_of_life: (_) => ["<iframe src='/games/game_of_life/index.html' width='650px' height='650px' frameBorder='0'></iframe>", 1, 0],
        puissance4: (_) => ["<iframe src='/games/puissance4/index.html' width='750px' height='550px' frameBorder='0'></iframe>", 1, 0],
        lsd: (_) => ["<iframe src='/games/lsd/index.html' width='400px' height='400px' frameBorder='0'></iframe>", 1, 0],
        btn1: (_) => ["<br><div class='btn-container'><div class='btn1'>btn1</div><div class='btn1'>btn2</div></div>", 1, 0],
        btn: (_) => ["<br><div class='btn-container'><div class='btn'>btn1</div><div class='btn'>btn2</div></div>", 1, 0],
        id: (_) => [new Date().getTime().toString().slice(-6), 0, 0],
        drag_test: (_, __, _p) => bash.func.drag_test(_, __, _p),
        not_found: (_) => [bash.errors.com_not_found(_), 0, 1],
        next_event_name: (_) => ["End of tp & Stream", 0, 0],
        load: (_) => ["<span class='load'></span>"],
        _flow: (_) => ["flow running ...", 0, 0],
        h: (_) => [bash.command.history(), 0, 0],
        pwd: (_) => [bash.path, 0, 0],
        ls: (_) => bash.func.ls(_),
        cd: (_) => bash.func.cd(_),
        ps: (_) => bash.func.ps(_),
        cat: (_) => bash.func.cat(_),
        flow: (_) => exec_flow(true),
        kill: (_) => bash.func.kill(_),
        bark: (_) => bash.func.bark(_),
        echo: (_) => bash.func.echo(_),
        mkdir: (_) => bash.func.mkdir(_),
        clear: (_) => bash.func.clear(_),
        github: (_) => bash.func.github(_),
        gui: (_, __) => bash.func.gui(_, __),
    },
    async_command: {
        nano: async (_) => await bash.func.nano(_),
        curl: async (_, __, _p) => await bash.func.curl(_, __, _p),
    },
    github: {
        ls: async (_) => await bash.func.gh_repos(_),
        cat: async (_) => await bash.func.gh_cat(_),
        bye: async (_) => bash.func.bye(),
        cd: async (_) => await bash.func.gh_cd(_),
        not_perm: async (_) => [bash.errors.github_err(_[0]), 0, 1],
        com_not_per: ["mkdir", "touch", "github", "com_not_per", "nano"],
    },
    exec: async (_, __, _p) => {
        bash.in_exec = true;
        bash.com().setAttribute("contenteditable", "false");
        if (_.at(-1).endsWith("quoi")) (new Audio(`/assets/sounds/feur/${bash.func.rand(1, 6)}.mp3`)).play();
        if (bash.venv == "git") {
            if (bash.github.com_not_per.includes(_[0])) return bash.github.not_perm(_, __, _p);
            if (bash.github.hasOwnProperty(_[0])) return await bash.github[_[0]](_, __, _p);
        }
        if (bash.command.hasOwnProperty(_[0])) return bash.command[_[0]](_, __, _p);
        if (bash.async_command.hasOwnProperty(_[0])) return await bash.async_command[_[0]](_, __, _p);
        return [bash.command.not_found(_[0]), 0, 1];
    },
    color: {
        white: "#cfd2d1",
        green: "#7ed321",
        lightblue: "#55b5db",
        lightgray: "#d4d4d4",
        pre: "#727474",
        red: "#ba1414",
        blue: "#1a8cff",
        yellow: "#cad411",
        pink: "#ff1a8c",
    },
    errors: {
        com_not_found: (_) => _ + ": command not found",
        cd_not_found: (_) => "cd: no such file or directory: " + _,
        cd_not_dir: (_) => "cd: not a directory: " + _,
        mkdir_miss: (_) => "mkdir: missing operand",
        mkdir_not_dir: (_) => "mkdir: cannot create directory ‘" + _ + "’: Not a directory",
        mkdir_exists: (_) => "mkdir: cannot create directory ‘" + _ + "’: File exists",
        ls_not_found: (_) => "ls: " + _ + ": No such file or directory",
        cat_not_found: (_) => "cat: " + _ + ": No such file or directory",
        cat_is_dir: (_) => "cat: " + _ + ": Is a directory",
        github_err: (_) => "github: command ‘" + _ + "’: permission denied",
        github_req: (_) => "github: command ‘" + _ + "’: request failed",
        kill_not_found: (_) => "kill: " + _ + ": No such process",
        kill_param_not: (_) => "kill: " + _ + ": illegal argument",
        kill_no_arg: (_) => "kill: " + _ + ": missing pid",
        gui: (_) => "gui: missing app name",
        gui_not_found: (_) => "gui: " + _ + ": app not found",
    },
    flow: ["next_event_name", "next_event_time", "btn1", "btn", "ls", "mkdir github", "cd github", "cd ..", "nano", "drag_test --app dragon", "drag_test --title puissance4 --content '/games/puissance4/index.html' --app test", "ps"],
    history: [],
    id_hist: 0,
    file_type: ["file", "directory"],
    path: "/",
    gh_path: "/",
    directory: {
        dir: {
            test_file: {
                type: 0,
                content: "coucou\nles engantje suis la pour manger vos daronne\n2",
                name: "test_file",
                last_update: 1650997968536,
            },
            test_folder: {
                type: 1,
                dir: {
                    tes_folder: {
                        type: 0,
                        content: "coucou\nles engantje suis la pour manger vos daronne\n1\n",
                        name: "tes_folder",
                        last_update: 1650997968536,
                    },
                    "..": () => bash.func.get_path("/"),
                    ".": () => bash.func.get_path("/test_folder"),
                },
                name: "test_folder",
                last_update: 1650997968536,
            },
            "..": () => bash.func.get_path("/"),
            ".": () => bash.func.get_path("/"),
        },
    },
};

if (typeof String.prototype.trim === "undefined") {
    String.prototype.trim = function () {
        return String(this).replace(/^\s+|\s+$/g, "");
    };
}

if (typeof String.prototype.replaceAt === "undefined") {
    String.prototype.replaceAt = function (index, char) {
        let a = this.split("");
        a[index] = char;
        return a.join("");
    };
}

if (typeof String.prototype.extractContent === "undefined") {
    String.prototype.extractContent = function () {
        let span = document.createElement("span");
        span.innerHTML = this;
        return span.textContent || span.innerText;
    };
}

if (typeof String.prototype.comSplit === "undefined") {
    String.prototype.comSplit = function com(h, s) {
        for (var u = h || /\s/g, n = !1, p = !1, t = [], i = [], o = this.split(""), r = 0; r < o.length; ++r) {
            var e = o[r],
                g = e.match(u);
            "'" !== e || p ? ('"' !== e || n ? (n || p || !g ? t.push(e) : 0 < t.length ? (i.push(t.join("")), (t = [])) : h && i.push(e)) : (!0 === s && t.push(e), (p = !p))) : (!0 === s && t.push(e), (n = !n));
        }
        return 0 < t.length ? i.push(t.join("")) : h && i.push(""), i;
    };
}

if (typeof Object.prototype.get === "undefined") {
    Object.prototype.get = function (def, ..._) {
        if (Array.isArray(_)) for (let i = 0; i < _.length; i++) if (this.hasOwnProperty(_[i])) return this[_[i]];
        return this.hasOwnProperty(_) ? this[_] : def;
    };
}

async function set_privew(e) {
    let el = (e?.target || e)?.closest(".tooltiptext");
    if (!el) return;
    let canvas = await html2canvas(document.querySelector(`[id='${el.id.split("_")[0]}_iframe']`).contentDocument.body);
    el.innerHTML = el.textContent;
    el.appendChild(canvas);
}

function get_max_index() {
    let max = 1;
    document.querySelectorAll(".dragable").forEach((el) => {
        max = Math.max(max, el.style["z-index"] || 20);
    });
    return max;
}

const scrollToBottom = (node) => {
    window.scrollTo(0, node.scrollHeight);
};

function aElt(type, text, color, classe, id) {
    if (!text) return;
    if (typeof text === "object") text = text[0];
    let line = document.createElement(type);
    if (classe) line.classList.add(classe);
    if (id) line.id = id;
    line.innerHTML = text;
    line.style.color = color;
    bash.tag.insertBefore(line, bash.com());
}

async function exec_command(com) {
    if (!com) return;
    if (com[0] != "_") aElt("span", com, bash.color.white);
    com = com.trim();
    bash.history.push(com);
    bash.id_hist++;
    let coms = com.comSplit().filter((f) => f);
    bash.tag.insertBefore(bash.break(), bash.com());
    let out = true,
        br = 0,
        err = 0;
    let param = {};
    for (let i = 0; i < coms.length; i++) {
        if (coms[i][0] == "-") param[coms[i]] = [...(param[coms[i]] || []), (coms[i + 1] || "-")[0] != "-" ? coms[++i] : true];
    }
    [out, br, err] = await bash.exec(coms, com, param);
    aElt("span", out, err ? bash.color.red : bash.color.lightgray);
    if (out && !br) bash.tag.insertBefore(bash.break(), bash.com());
}

async function exec_flow(flow) {
    if (flow) {
        await exec_command("_flow");
        pre_command();
    }
    for (let i = 0; i < bash.flow.length; i++) {
        await exec_command(bash.flow[i]);
        if (!flow || i < bash.flow.length - 1) pre_command();
    }
}

function pre_command() {
    bash.com().innerText = "";
    bash.tag.insertBefore(bash.break(), bash.com());
    if (bash.venv) {
        aElt("span", `(${bash.venv}:`, bash.color.pink, "venv");
        aElt("span", `${bash.gh_path}`, bash.color.lightblue, "venv");
        aElt("span", `) `, bash.color.pink, "venv");
    }
    aElt("span", bash.user, bash.color.green);
    aElt("span", "@", bash.color.white);
    aElt("span", bash.host, bash.color.green);
    aElt("span", bash.clos() + " ", bash.color.lightblue);
    bash.com().setAttribute("contenteditable", "true");
    bash.in_exec = false;
    bash.com().focus();
    scrollToBottom(bash.bot);
    bash.com().innerText = "";
    document.querySelectorAll("pre code").forEach((el) => {
        if (el.classList.length == 0) {
            hljs.highlightElement(el);
            hljs.lineNumbersBlock(el);
        }
    });
}

function init_prompt() {
    bash.intro.forEach((line) => {
        let code = document.createElement("span");
        code.textContent = line;
        code.style.color = bash.color.pre;
        code.style.display = "block";
        bash.tag.insertBefore(code, bash.com());
    });
}

function setCaret(pos) {
    let el = document.getElementById("command");
    let range = document.createRange();
    let sel = window.getSelection();
    range.setStart(el.childNodes[0], pos);
    range.collapse(true);
    sel.removeAllRanges();
    sel.addRange(range);
}

async function init_enter_command() {
    return document.addEventListener(
        "keydown",
        async function (e) {
            if (e.key.length == 1 || [8, 13, 32, 37, 38, 39, 40].includes(e.keyCode)) {
                bash.auto = false;
                bash.iauto = 0;
            }
            if (e.keyCode == 13) {
                if (bash.in_exec) return;
                await exec_command(bash.com().textContent);
                pre_command();
            }
            if (e.keyCode == 38) {
                if (bash.in_exec) return;
                bash.id_hist = Math.max(bash.id_hist - 1, 0);
                bash.com().textContent = bash.history[bash.id_hist];
            }
            if (e.keyCode == 40) {
                if (bash.in_exec) return;
                bash.id_hist = Math.min(bash.id_hist + 1, bash.history.length);
                bash.com().textContent = bash.history[bash.id_hist];
            }
            if (e.keyCode == 9) {
                e.preventDefault();
                e.stopPropagation();
                if (bash.in_exec) return;
                bash.iauto++;
                if (bash.auto === false) {
                    let com = bash.com().textContent.slice(0, document.getSelection().focusOffset.valueOf()).split(/\s+/).at(-1);
                    bash.cauto = document.getSelection().focusOffset;
                    bash.auto = com;
                    bash.iauto = 0;
                }
                let com = bash.com().textContent;
                let cur = bash.cauto;
                let coms = [];

                if (com.slice(0, cur).split(/\s+/).length > 1 && bash.venv !== "git") {
                    coms = bash.func.ls();
                    if (coms[2] === 1) return;
                    coms = coms[0]
                        .extractContent()
                        .split(/\s+/)
                        .filter((f) => f);
                } else {
                    coms = Object.keys(bash.command);
                    coms = coms.concat(Object.keys(bash.async_command));
                    if (bash.venv === "git") coms = coms.concat(Object.keys(bash.github)).filter((f) => !bash.github.com_not_per.includes(f));
                    coms = coms.filter((f) => f && f[0] != "_" && f.startsWith(bash.auto)).sort();
                    if (!coms.length) return;
                }

                for (; com[cur] && com[cur] != " "; com = com.replaceAt(cur++, " "));
                com = com.slice(0, bash.cauto) + coms[bash.iauto % coms.length].slice(bash.auto.length) + com.slice(bash.cauto);
                bash.com().textContent = com;
                setCaret(bash.cauto + coms[bash.iauto % coms.length].slice(bash.auto.length).length);
            }
        },
        true
    );
}

async function start() {
    init_prompt();
    pre_command();
    await exec_flow();
    let com = init_enter_command();
}

start();
