
let mobilenet;
let video;
let label = '';
let num;

///////////////perlin//////////

let inc = 0.1;
let scl = 17;
let cols, rows;

let zoff = 0;

let myFont;
function preload() {
  myFont = loadFont('ok.otf');
}

///////////////////////////////


function modelReady() {
  console.log('Model is ready!!!');
  mobilenet.predict(gotResults);
}

function gotResults(error, results) {
  if (error) {
    console.error(error);
  } else {
 
    console.log(results);
    num = results[0].probability;
    
    label = results[0].className;
    //delay(500);
    mobilenet.predict(gotResults);
  }
}

// function imageReady() {
//   image(puffin, 0, 0, width, height);
// }

function setup() {
  createCanvas(windowWidth, windowHeight);
  video = createCapture(VIDEO);
  video.hide();
  background(0);
  mobilenet = ml5.imageClassifier('MobileNet', video, modelReady);
  cols = floor(width/scl);
  rows = floor(height/scl);
}

function draw() {

  ////////////text/////////////////
  
  background(0, 30);
  textFont(myFont);
  fill(255);
  textSize(12);
  let i;
  let aba = 300*num;
  i=aba;
  text(label, 10, 10+i);
  text(num, width-180, height-i);

  background(0, 40);
  let yoff = 0;
  for (let y = 0; y<rows; y++){
    let xoff = 0;
    for(let x = 0; x<cols; x++){
      let index = ( x + y * width)*4;
      let angle = noise(xoff, yoff, zoff)*TWO_PI;
      let v =p5.Vector.fromAngle(angle);
      xoff += inc;
      //stroke(0);
      push();
      translate(x*scl, y*scl);
      rotate(v.heading());

      stroke (num*100, 255-(num*400), 1.4*num*400, num*400);
      strokeWeight(0.1);
      line(0, 0, width/4, width/4);
      pop();
      
      // fill(r);
      // rect(x*scl, y *scl, scl, scl);
    }
    yoff+= inc;
    
    zoff += 0.005;
  }

  //////////////////////////////////ml////////////////

  //background(0);
  //image(video, 0, 0);
  // fill(255);
  // textSize(32);
  // text(label, 10, height - 50);
  // text(num, 10, height - 10);
}