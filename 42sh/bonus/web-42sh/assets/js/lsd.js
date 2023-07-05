function Ctrl() {
    this.rows = 50;
    this.columns = 50;
    this.maxSize = 50;
    this.minSize = 10;
    this.alpha = 1;
}
var ctrl = new Ctrl();
var w = 400,
    h = 400,
    count = 40,
    columns = 10,
    Msize = 60,
    msize = 0,
    colors = ["#ff0000", "#ff7f00", "#ffff00", "#00ff00", "#0000ff", "#4b0082", "#8b00ff"],
    cover = "rgba(0, 0, 0, .1)";
c.width = w;
c.height = h;
var ctx = c.getContext("2d");
var frame = 0;
let gg = { columns: 100, rows: 100, minSize: 10, maxSize: 100, alpha: 1 };
function anim() {
    window.requestAnimationFrame(anim);

    ctx.fillStyle = "rgba(0, 0, 0, " + ctrl.alpha + ")";
    ctx.fillRect(0, 0, w, h), ++frame;
    var frameClone = frame;

    for (var j = 0; j < ctrl.columns; ++j) {
        var y = 10;
        var x = (w / ctrl.columns) * j;
        frameClone += ctrl.rows;
        for (var i = 0; i < ctrl.rows; ++i) {
            ctx.fillStyle = colors[i % colors.length];
            var side = Math.abs(Math.sin((((frameClone / ctrl.rows) * h) / ctrl.rows / ctrl.rows) * 6 + (i / ctrl.rows) * 8)) * ctrl.maxSize + ctrl.minSize;
            y += side;
            ctx.fillRect(x - side / 2 + ctrl.maxSize / 2, (i * h) / ctrl.rows, side, side);
        }
    }
}
anim();
