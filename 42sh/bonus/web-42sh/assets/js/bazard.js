function index(j, i) {
    return i + j * col;
}
function lancerDebut() {
    popu.start();
}
function mousePressed() {
    let i = floor((mouseX / width) * ligne);
    let j = floor((mouseY / height) * col);
    popu.cases[index(i, j)].isAlive = !popu.cases[index(i, j)].isAlive;
}
function keyPressed() {
    if (keyCode == ENTER) {
        started = !started;
    }
    if (keyCode == 82) {
        for (let i in popu.cases) {
            if (random(1) > 0.5) {
                popu.cases[i].isAlive = true;
            }
        }
    }
    if (keyCode == 67) {
        for (let i in popu.cases) {
            popu.cases[i].isAlive = false;
            popu.cases[i].tampisAlive = false;
        }
    }
}
function lancement() {
    started = !started;
    if (started) {
        lancer.html("Stop");
    } else {
        lancer.html("Relancer");
    }
}
function effacement() {
    for (let i in popu.cases) {
        popu.cases[i].isAlive = false;
        popu.cases[i].tampisAlive = false;
    }
}
function remplir() {
    for (let i in popu.cases) {
        if (random(1) > 0.5) {
            popu.cases[i].isAlive = true;
        }
    }
}

class Case {
    constructor(i, j) {
        this.i = i;
        this.j = j;
        this.isAlive = false;
    }

    show() {
        let x = (this.i * width) / ligne;
        let y = (this.j * height) / col;
        stroke(255);
        strokeWeight(1);
        if (this.isAlive) {
            fill(255);
        } else {
            fill(27);
        }
        rect(x, y, width / ligne, height / col);
    }

    findVoisins() {
        let i = this.i;
        let j = this.j;
        this.voisins = [];
        if (i + 1 < ligne) this.voisins.push(popu.cases[index(i + 1, j)]);
        if (i + 1 < ligne && j + 1 < col) this.voisins.push(popu.cases[index(i + 1, j + 1)]);
        if (i + 1 < ligne && j - 1 >= 0) this.voisins.push(popu.cases[index(i + 1, j - 1)]);
        if (j + 1 < col) this.voisins.push(popu.cases[index(i, j + 1)]);
        if (j - 1 >= 0) this.voisins.push(popu.cases[index(i, j - 1)]);
        if (i - 1 >= 0) this.voisins.push(popu.cases[index(i - 1, j)]);
        if (i - 1 >= 0 && j - 1 >= 0) this.voisins.push(popu.cases[index(i - 1, j - 1)]);
        if (i - 1 >= 0 && j + 1 < col) this.voisins.push(popu.cases[index(i - 1, j + 1)]);
    }

    update() {
        this.voisinsVivants = 0;
        for (let i in this.voisins) {
            if (this.voisins[i].isAlive) {
                this.voisinsVivants++;
            }
        }
        let i = this.i;
        let j = this.j;
        if (!this.isAlive && this.voisinsVivants == 3) {
            this.tampisAlive = true;
        }
        if (this.isAlive && this.voisinsVivants != 2 && this.voisinsVivants != 3) {
            this.tampisAlive = false;
        }
        if ((this.isAlive && this.voisinsVivants == 2) || (this.isAlive && this.voisinsVivants == 3)) {
            this.tampisAlive = true;
        }
    }

    terminer() {
        this.isAlive = this.tampisAlive;
    }
}

class Popu {
    constructor() {
        this.taille = col * ligne;
        this.cases = [];
        this.actu = false;
        for (let i = 0; i < ligne; i++) {
            for (let j = 0; j < col; j++) {
                this.cases.push(new Case(i, j));
            }
        }
    }
    voisins() {
        for (let i = 0; i < this.taille; i++) {
            this.cases[i].findVoisins();
        }
    }
    start() {
        for (let i = 0; i < this.taille; i++) {
            this.cases[i].show();
        }
    }
    run() {
        this.actu = false;
        for (let i = 0; i < this.taille; i++) {
            this.cases[i].show();
            this.cases[i].update();
        }
        this.actu = true;
    }
    termine() {
        for (let i = 0; i < this.taille; i++) {
            this.cases[i].terminer();
        }
    }
}

let col = 50;
let ligne = 50;
let popu;
let started = false;

let effacer, lancer, rand;

function setup() {
    createCanvas(600, 600);
    popu = new Popu();
    popu.voisins();

    effacer = createButton("Effacer");
    lancer = createButton("Lancer");
    rand = createButton("Remplir");

    effacer.position(width / 2 - (effacer.width * 3) / 2, height + 10);
    lancer.position(width / 2 - (effacer.width * 1) / 2, height + 10);
    rand.position(width / 2 - (lancer.width * -1) / 2, height + 10);

    effacer.mousePressed(effacement);
    lancer.mousePressed(lancement);
    rand.mousePressed(remplir);
}

function draw() {
    background(220);
    if (!started) {
        frameRate(10);
        //voir bazard.js
        lancerDebut();
    }
    if (started) {
        //voir popu.js
        popu.run();
        if (popu.actu) {
            //voir bazard.js
            popu.termine();
        }
        frameRate(10);
    }
}
