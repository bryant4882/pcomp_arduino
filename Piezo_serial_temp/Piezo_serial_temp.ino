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
  pulse = 150;
  delay_min = 300;
  delay_max = 50000;
  
  pinMode(pie, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(pot1, INPUT);

}

void loop() {



  current_time = micros();
  makeSound();
  updatePulse();
}

void makeSound(){
  if(current_time-last_pulse_time > frequency){
    frequency = updateFrequency();
    last_pulse_time = current_time;
  }
}

unsigned long updateFrequency(){

 //if (Serial.available() > 0) { // if there's serial data available
 // inByte = Serial.read();   // read 
 
  
  //float nf = map(inByte, 0, 130, delay_min, delay_max);
//  unsigned long nf = (unsigned long) map(analogRead(pot), 0, 1023, delay_min, delay_max);
//  Serial.println(nf);
  //Serial.println(analogRead(pot));
//  return nf;
 return (unsigned long) map(analogRead(pot), 0, 1023, delay_min, delay_max);
 
 //}
//  return int(delay_min + float(analogRead(pot)) / 1023.0 * (delay_max - delay_min));
}

void updatePulse(){

  if (current_time - last_pulse_time < pulse){
    digitalWrite(pie, HIGH);
  }else{
    digitalWrite(pie, LOW);
  }
}
