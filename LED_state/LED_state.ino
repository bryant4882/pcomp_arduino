const int l1 = 13;
const int l2 = 12;
const int but = 2;

int last_time = 0;
int buttonLast = 1;
boolean buttonState;
int duration = 0;
long holdb;
long intervalb;


void setup() {
  pinMode(but, INPUT_PULLUP);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);

}

void loop() {

  buttonState = digitalRead(but);
  unsigned long current_time = millis();

  if(buttonLast == HIGH) {
    last_time = current_time;
    duration = 0;
  } 
  
  if (buttonState == LOW && buttonLast == LOW) {
    duration = current_time - last_time;
  } 
    
  buttonLast = buttonState;

  if (duration >= 3000) {
    digitalWrite(l1, HIGH);
    //digitalWrite(l2, LOW);
  }
  else {
    digitalWrite (l1, LOW);
  }
    if (duration >= 6000) {
      digitalWrite (l2, HIGH);
    }
  }
