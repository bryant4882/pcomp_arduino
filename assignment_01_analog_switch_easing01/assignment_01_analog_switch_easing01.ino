#define LED_PIN 5
#define pot A0

float currentValue;
float targetValue;
float easingAmount;
const int tip = 511;     //set tipping point
float targetValue1;


void setup(){
  currentValue = 0;
  targetValue = 255;
  easingAmount = .125;
  targetValue1 = 0;        //ease off target
  
  Serial.begin(9600);
}

void loop(){
  
  int val = 0;
  val = analogRead (pot);
  Serial.print(val);
  Serial.print("/");
  //delay(250);             //checkin analog val

  if(val <= tip){
    currentValue += easingAmount * ( targetValue1 - currentValue );
  }else{
  currentValue += easingAmount * ( targetValue - currentValue );
  }
  //Serial.print("currentValue: ");
  //Serial.print(currentValue);
  //Serial.print("\t targetValue: ");
  //Serial.println(targetValue);
  analogWrite(LED_PIN, (int) currentValue);
  delay(250);
}
