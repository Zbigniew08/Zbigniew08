const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');
const width = canvas.width;
const height = canvas.height;

const deska1 = {x:10,y:200,width:10,height:40};
const deska2 = {x:590,y:200,width:10,height:40};
const pilka = {x:300,y:200,vx:1,vy:1};

let punkty1 = 0;
let punkty2 = 0;

pilka.draw = function() {
	ctx.beginPath();
	ctx.fillStyle = "red";
	ctx.arc(this.x, this.y, 10,0, 2 * Math.PI);
	ctx.fill();
};

deska1.draw = function() {
	ctx.fillStyle = "black";
    ctx.fillRect(this.x, this.y, this.width, this.height);
};

deska2.draw = function() {
	ctx.fillStyle = "black";
    ctx.fillRect(this.x, this.y, this.width, this.height);
};


document.addEventListener('keydown', function(e){
	e.preventDefault();
	if(e.code == "KeyA"){ 
        deska1.y +=15;
    }
	else if(e.code == "KeyD"){ 
        deska1.y -=15;
    }
})

document.addEventListener('keydown', function(e){
	e.preventDefault();
	if(e.code == "ArrowRight"){ 
        deska2.y +=15;
    }
	else if(e.code == "ArrowLeft"){ 
        deska2.y -=15;
    }
})

function update() {
	ctx.clearRect(0,0, canvas.width, canvas.height);
    if (pilka.y + pilka.vy > deska1.y && pilka.y + pilka.vy < deska1.y + deska1.height && pilka.x + pilka.vx == deska1.x) {
		pilka.vx = -pilka.vx;
	}
    if (pilka.y + pilka.vy > deska2.y && pilka.y + pilka.vy < deska2.y + deska2.height && pilka.x + pilka.vx == deska2.x) {
		pilka.vx = -pilka.vx;
	}
    if (pilka.y + pilka.vy > height || pilka.y + pilka.vy < 0) {
		pilka.vy = -pilka.vy;
	}
    pilka.x += pilka.vx;
    pilka.y += pilka.vy;
	deska1.draw();
    deska2.draw();
    pilka.draw();
	window.requestAnimationFrame(update);
	// jak funkcja update zostanie wywołana to metoda deska.draw()
	// spowoduje narysowanie deski ponownie z wartoścami x i y uaktualnionym przez
	// obsługę zdarzenie na naciśnięcie klawisza. 
}

update();