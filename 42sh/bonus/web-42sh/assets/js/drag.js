function dragElement(elmnt) {
    let pos1 = 0,
        pos2 = 0,
        pos3 = 0,
        pos4 = 0;
    if (elmnt.getElementsByClassName("windows_header")[0]) elmnt.getElementsByClassName("windows_header")[0].onmousedown = dragMouseDown;
    else elmnt.onmousedown = dragMouseDown;
    function dragMouseDown(e) {
        e = e || window.event;
        e.preventDefault();
        elmnt.style.zIndex = get_max_index() + 1;
        if (e.srcElement.classList.contains("_close")) {
            let app = document.querySelector(`[id="${elmnt.id}_tooltip"]`);
            if (app.closest(".tool_group").childElementCount == 1) app.closest(".db_item").remove();
            else app.remove();
            elmnt.remove();
        } else if (e.srcElement.classList.contains("_full")) {
            e.srcElement.classList.remove("_full");
            e.srcElement.classList.add("_reduce");
            this.parentElement.classList.add("_fullscreen");
        } else if (e.srcElement.classList.contains("_reduce")) {
            e.srcElement.classList.remove("_reduce");
            e.srcElement.classList.add("_full");
            this.parentElement.classList.remove("_fullscreen");
        } else if (e.srcElement.classList.contains("_minus")) {
            let parent = this.parentElement;
            parent.style.visibility = "hidden";
            parent.style["z-index"] = -1;
            return;
        }
        pos3 = e.clientX;
        pos4 = e.clientY;
        document.onmouseup = closeDragElement;
        document.onmousemove = elementDrag;
    }

    function elementDrag(e) {
        e = e || window.event;
        e.preventDefault();
        let parent = e.srcElement;
        while (!parent?.classList?.contains("dragable")) {
            if (!parent.parentElement) break;
            parent = parent.parentElement;
        }
        if (parent?.classList?.contains("_fullscreen")) return;
        pos1 = pos3 - e.clientX;
        pos2 = pos4 - e.clientY;
        pos3 = e.clientX;
        pos4 = e.clientY;
        elmnt.style.top = elmnt.offsetTop - pos2 + "px";
        elmnt.style.left = elmnt.offsetLeft - pos1 + "px";
        if (elmnt.offsetTop < 0) elmnt.style.top = 0;
        if (elmnt.offsetLeft < 0) elmnt.style.left = 0;
    }

    function closeDragElement() {
        document.onmouseup = null;
        document.onmousemove = null;
    }
}

function resizeIframe(obj) {
    obj.style.height = obj.contentWindow.document.documentElement.scrollHeight + "px";
    obj.style.width = obj.contentWindow.document.documentElement.scrollWidth + "px";
}
