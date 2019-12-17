/*
   Analog piezo using serial data from p5 sketch as frequency interval
   11/29
 */

/////////////////////piezo////////////////////

const int pie = 8;
const int pot = A0;
const int pot1 = A1;

unsigned long last_pulse_time, current_time;
unsigned long pulse, frequency;
float delay_min, delay_max;




void setup() {

  Serial.begin(9600);




  last_pulse_time = 0;
  current_time = 0;
  frequency = 0;
  pulse = 0;
  delay_min = 100;
  delay_max = 50000;
  
  pinMode(pie, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(pot1, INPUT);

}

void loop() {


  current_time = micros();
  


  makeSound();


  
  updatePulse();
  updatePulse1();

}

void makeSound(){
  if(current_time-last_pulse_time > frequency){
    frequency = updateFrequency();
    last_pulse_time = current_time;
  }
}

void makeSound1(){      
  if(current_time-last_pulse_time > frequency){
    frequency = updateFrequency1();
    last_pulse_time = current_time;
  }
}

unsigned long updateFrequency(){

// if (Serial.available() > 0) { // if there's serial data available
 //int inByte = Serial.read();   // read 
 //int inByte = Serial.parseInt();
 int inByte = Serial.read();   // read
 Serial.write(inByte); 
 
  
 //float nf = map(inByte, 0, 130, delay_min, delay_max);
//  unsigned long nf = (unsigned long) map(analogRead(pot), 0, 1023, delay_min, delay_max);
//  Serial.println(nf);
  //Serial.println(analogRead(pot));
 //return nf;

 
 return (unsigned long) map(inByte, 0, 255, delay_min, delay_max);
 //return (unsigned long) map(analogRead(pot), 0, 1023, delay_min, delay_max);    
 
 
//  return int(delay_min + float(analogRead(pot)) / 1023.0 * (delay_max - delay_min));
//}    //////if ser read

}


unsigned long updateFrequency1(){

// if (Serial.available() > 0) { // if there's serial data available
 //int inByte = Serial.read();   // read 
 //int inByte = Serial.parseInt();
 int inByte = Serial.read();   // read 
 
  
 //float nf = map(inByte, 0, 130, delay_min, delay_max);
//  unsigned long nf = (unsigned long) map(analogRead(pot), 0, 1023, delay_min, delay_max);
//  Serial.println(nf);
  //Serial.println(analogRead(pot));
 //return nf;

 
 return (unsigned long) map(inByte, 0, 255, 300, 30000);
 //return (unsigned long) map(analogRead(pot), 0, 1023, 300, 3000);    
 
 
//  return int(delay_min + float(analogRead(pot)) / 1023.0 * (delay_max - delay_min));
//} ////if sr read

}

void updatePulse(){
//
//if (Serial.available() > 0) { // if there's serial data available
 int inByte = Serial.read();   // read 
 //int inByte = Serial.parseInt();

  pulse = (unsigned long) map(inByte, 0, 255, 1, 5000);
  //pulse = (unsigned long) map(analogRead(pot1), 0, 1023, 1, 5000);
  
  

  if (current_time - last_pulse_time < pulse){
    digitalWrite(pie, HIGH);
  }else{
    digitalWrite(pie, LOW);
  }
// }  ///////if sr read
} 

void updatePulse1(){


// if (Serial.available() > 0) { // if there's serial data available
 int inByte = Serial.read();   // read 
 //int inByte = Serial.parseInt();


  pulse = (unsigned long) map(inByte, 0, 255, 40, 2000);
  //pulse = (unsigned long) map(analogRead(pot1), 0, 1023, 600, 8000);
  
  
  //pulse = 300;
  //Serial.println(pulse);
  if (current_time - last_pulse_time < pulse){
    digitalWrite(pie, HIGH);
  }else{
    digitalWrite(pie, LOW);
  }
// } /////// if sr read 
}
