int byteRead;
int ledPin = 12;

char c = ' ';

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);}

  void loop() {
    if(Serial.available())
    {
      Serial.print("ok");
      char c = Serial.read();
      if (c=='2'){digitalWrite(ledPin, LOW);}
      if (c=='1'){digitalWrite(ledPin, HIGH);}
    }
  }
