int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if (switchState == LOW) {
    
    //Button not Pressed
    
    digitalWrite(3, HIGH); //Green on
    digitalWrite(4, LOW); //Red off
    digitalWrite(5, LOW); //Red off
  }

  else {
    
    //Button pressed

    digitalWrite(3, LOW); //Green off
    digitalWrite(4, HIGH); //Red on
    digitalWrite(5, HIGH); //Red on

    delay(150); 
    //Light LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(150); 
  
  }

}
