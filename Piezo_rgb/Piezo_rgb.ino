/*
   Analog piezo using serial data from p5 sketch as frequency interval
   11/29
 */

#include <Wire.h>
#include <SparkFun_APDS9960.h>

/////////////////////piezo////////////////////

const int pie = 8;
const int pot = A0;
const int pot1 = A1;

unsigned long last_pulse_time, current_time;
unsigned long pulse, frequency;
float delay_min, delay_max;


/////////rgb sensor/////////

SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;


//////////////////////////////////

void setup() {

  Serial.begin(9600);

  //////////////rgb//////////

  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - ColorSensor"));
  Serial.println(F("--------------------------------"));
  
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  
  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }
  
  // Wait for initialization and calibration to finish
  delay(500);
  ///////////////////////////
  



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



    //color sense
    // Read the light levels (ambient, red, green, blue)
//  if (  !apds.readAmbientLight(ambient_light) ||
//        !apds.readRedLight(red_light) ||
//        !apds.readGreenLight(green_light) ||
//        !apds.readBlueLight(blue_light) ) {
//    Serial.println("Error reading light values");
//  } else {
//    Serial.print("Ambient: ");
//    Serial.print(ambient_light);
//    Serial.print(" Red: ");
//    Serial.print(red_light);
//    Serial.print(" Green: ");
//    Serial.print(green_light);
//    Serial.print(" Blue: ");
//    Serial.println(blue_light);
//  }


  current_time = micros();
  


  makeSound();
  makeSound1();
  
  //////////////way to do combination
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
// int inByte = Serial.read();   // read 
 
 //inByte = Serial.read();   // read 
 
  
 //float nf = map(inByte, 0, 130, delay_min, delay_max);
//  unsigned long nf = (unsigned long) map(analogRead(pot), 0, 1023, delay_min, delay_max);
//  Serial.println(nf);
  //Serial.println(analogRead(pot));
 //return nf;


  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
  } else {
//    Serial.print("Ambient: ");
//    Serial.print(ambient_light);
//    Serial.print(" Red: ");
//    Serial.print(red_light);
//    Serial.print(" Green: ");
//    Serial.print(green_light);
//    Serial.print(" Blue: ");
//    Serial.println(blue_light);
  }

     int valA = ambient_light;
    Serial.println (valA);
 //return (unsigned long) map(inByte, 0, 110, delay_min, delay_max);
 return (unsigned long) map(analogRead(pot), 0, 350, delay_min, delay_max);    

 
//  return int(delay_min + float(analogRead(pot)) / 1023.0 * (delay_max - delay_min));
//}

}


unsigned long updateFrequency1(){

// if (Serial.available() > 0) { // if there's serial data available
// int inByte = Serial.read();   // read 
 
 //inByte = Serial.read();   // read 
 
  
 //float nf = map(inByte, 0, 130, delay_min, delay_max);
//  unsigned long nf = (unsigned long) map(analogRead(pot), 0, 1023, delay_min, delay_max);
//  Serial.println(nf);
  //Serial.println(analogRead(pot));
 //return nf;

  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
  } else {
//    Serial.print("Ambient: ");
//    Serial.print(ambient_light);
//    Serial.print(" Red: ");
//    Serial.print(red_light);
//    Serial.print(" Green: ");
//    Serial.print(green_light);
//    Serial.print(" Blue: ");
//    Serial.println(blue_light);
  }
int valc = green_light;
Serial.println ("valc");
 
 //return (unsigned long) map(inByte, 0, 110, delay_min, delay_max);
 return (unsigned long) map(valc, 0, 170, 1300, 30000);    
 
 
//  return int(delay_min + float(analogRead(pot)) / 1023.0 * (delay_max - delay_min));
//}

}

void updatePulse(){
//
//  if (Serial.available() > 0) { // if there's serial data available
// int inByte1 = Serial.read();   // read 
  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
  } else {
//    Serial.print("Ambient: ");
//    Serial.print(ambient_light);
//    Serial.print(" Red: ");
//    Serial.print(red_light);
//    Serial.print(" Green: ");
//    Serial.print(green_light);
//    Serial.print(" Blue: ");
//    Serial.println(blue_light);
  }




int valB = blue_light;
Serial.println ("valB");
Serial.println (valB);

 
  
  
  
  //pulse = (unsigned long) map(inByte1, 0, 200, 1, 5000);
  pulse = (unsigned long) map(analogRead(pot1), 40, 170, 1, 5000);

  
  //pulse = 300;
  //Serial.println(pulse);
  if (current_time - last_pulse_time < pulse){
    digitalWrite(pie, HIGH);
  }else{
    digitalWrite(pie, LOW);
  }
}


void updatePulse1(){
//
//  if (Serial.available() > 0) { // if there's serial data available
// int inByte1 = Serial.read();   // read 


    if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
  } else {
//    Serial.print("Ambient: ");
//    Serial.print(ambient_light);
//    Serial.print(" Red: ");
//    Serial.print(red_light);
//    Serial.print(" Green: ");
//    Serial.print(green_light);
//    Serial.print(" Blue: ");
//    Serial.println(blue_light);
  }

  int vald = red_light;
  //Serial.println ("vald"+ vald);
  Serial.println ("vald");
  
  //pulse = (unsigned long) map(inByte1, 0, 200, 1, 5000);
  pulse = (unsigned long) map(vald, 40, 170, 40, 2000);
  
  
  //pulse = 300;
  //Serial.println(pulse);
  if (current_time - last_pulse_time < pulse){
    digitalWrite(pie, HIGH);
  }else{
    digitalWrite(pie, LOW);
  }
}
