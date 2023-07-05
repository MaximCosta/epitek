document.querySelector("#dock_bar").addEventListener("mouseover", (e) => {
    e.preventDefault();
    let ol = e.target.closest(".db_item");
    if (!ol) return;
    document.querySelectorAll(".db_item").forEach((el) => el.classList.add("notransition"));
    ol.classList.remove("notransition");
});

setInterval(function () {
    bash.next.s--;
    if (bash.next.s < 0) {
        bash.next.s = 59;
        bash.next.m--;
        if (bash.next.m < 0) {
            bash.next.m = 59;
            bash.next.h--;
            if (bash.next.h < 0) {
                bash.next.h = bash.next.m = bash.next.s = 0;
            }
        }
    }

    let th = document.querySelectorAll("span.th");
    let tm = document.querySelectorAll("span.tm");
    let ts = document.querySelectorAll("span.ts");
    for (let i = 0; i < th.length; i++) {
        th[i].textContent = bash.next.h;
        tm[i].textContent = bash.next.m;
        ts[i].textContent = bash.next.s;
    }
}, 1000);

setInterval(function () {
    let load = document.querySelectorAll("span.load");
    for (let i = 0; i < load.length; i++) {
        load[i].textContent = ".".repeat((load[i].textContent.length + 1) % 4);
    }
}, 250);

bash.com().addEventListener("focusout", (event) => {
    bash.com().focus();
});