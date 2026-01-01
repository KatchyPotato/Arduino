int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  //Calibrate Sensor
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  //Turn off LED after calibrating for 5 seconds
  digitalWrite(ledPin, LOW);
}

void loop() {
  //Read analog input and map to correct frequency range
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 100, 1500);
  //Play sound on pin 8 with tone() function call
  tone(8, pitch, 20);
  delay(10);

}
