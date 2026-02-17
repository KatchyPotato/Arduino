const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 5000;

void setup() {
  for(int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime  = millis();
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
  }
  // flash lights when last led lights
  if (led == 8) {
    delay(100);
    for (int flash = 0; flash < 5; flash++) {
      for (int pin = 2; pin < 8; pin++) {
        digitalWrite(pin, LOW);
      }
      delay(200);

      for (int pin = 2; pin < 8; pin++) {
        digitalWrite(pin, HIGH);
      }
      delay(200);
    }
    led++;
  }

  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState){
    for(int x = 2; x < 8; x++){
      digitalWrite(x, LOW);
    }

    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}


