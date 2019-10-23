// led
int led = 13;


// motor

int enPin = 9;            //Power out
int M1 = 10;               //motor1          
int M2 = 11;               //motor2
int sDir = 4;              //switch direction
int potPin = A0;           //ana in


// piezo

int piezo = 3;
int potenInput = A0;
int pValue;
int button = 4;
int currentTime = 0;
int pulseStart = 0;
int pulseDuration = 0;

// color

#include <Wire.h>
#include <SparkFun_APDS9960.h>

// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;


void setup() {

 //led

 pinMode(led, OUTPUT);
 digitalWrite(led, HIGH);

 // motor
 
 pinMode(M1, OUTPUT);
 pinMode(M2, OUTPUT);
 pinMode(enPin, OUTPUT);
 pinMode(sDir, INPUT_PULLUP);
 Serial.begin(9600);
  
 // piezo
 pinMode(button, INPUT_PULLUP);
 pinMode(potenInput, INPUT);
 pinMode(piezo, OUTPUT);
 Serial.begin(9600);

// color
  // Initialize Serial port
  Serial.begin(9600);
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



}


void loop() {

  // motor

   int speed = analogRead(potPin) / 4;    //modify speed
   boolean reverse = digitalRead(sDir);   //dir state
   setMotor(speed, reverse);              //(anar, boolean)


  //color sense
    // Read the light levels (ambient, red, green, blue)
  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
  } else {
    Serial.print("Ambient: ");
    Serial.print(ambient_light);
    Serial.print(" Red: ");
    Serial.print(red_light);
    Serial.print(" Green: ");
    Serial.print(green_light);
    Serial.print(" Blue: ");
    Serial.println(blue_light);
  }
  
  // Wait 1 second before next reading
  //delay(1000);
  
 // piezo value
    pValue = analogRead(potenInput);
    currentTime = millis();
    Serial.print("/");
    Serial.print(analogRead(potenInput));
    delay(200);
    //int val = analogRead(potenInput);
    int valA = ambient_light;
    int valB = blue_light;
    valA = map(valA, 0, 350, 3000, 8000);  //map ambient value
    valB = map(valB, 0, 200, 100, 6000);   //map blue
    tone(piezo, valA, valB);
     
}

  void setMotor(int speed, boolean reverse) 
  {
     // Set the speed of the motor
      analogWrite(enPin, speed);
      Serial.print(speed);
      Serial.print(", ");
      Serial.println(reverse);
      // If we should go reverse
      if (reverse) {
       digitalWrite(M1, HIGH);
       digitalWrite(M2, LOW);
       } else {
       digitalWrite(M1, LOW);
       // THIS IS THE PROBLEM!!!!!
       digitalWrite(M2, HIGH);
      }

  }
