const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);
  //Setup pins
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  
}

void loop() {
  //Ged sensor values
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  //Print sensor values
  Serial.print("\nRaw Sensor Values\nred: ");
  Serial.println(redSensorValue);
  Serial.print("green: ");
  Serial.println(greenSensorValue);
  Serial.print("blue: ");
  Serial.println(blueSensorValue);
  //Convert sensor values for analogWrite()
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;
  //Divide by 4 to convert from 0-1023 to 0-255
  //Print color values
  delay(500);
  Serial.print("\nMapped Sensor Values\nred: ");
  Serial.println(redValue);
  Serial.print("green: ");
  Serial.println(greenValue);
  Serial.print("blue: ");
  Serial.println(blueValue);
  //Set LED light levels with analogWrite(), set pins, and color values
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
  delay(2000);

  
  
}
