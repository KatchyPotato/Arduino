const int sensorPin = A0;
const float baselineTemp = 22.75;

void setup() {
  Serial.begin(9600); //Open the serial port  
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  //Convert reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(" , Volts ");
  Serial.print(voltage);
  
  Serial.print(" , degrees C: ");
  //Convert voltage to degrees clesius
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  //Turn on lights based on temperature 

  if(temperature < baselineTemp + 2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  
  } else if(temperature >= baselineTemp + 2 && temperature < baselineTemp + 4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  
  }else if(temperature >= baselineTemp + 4 && temperature < baselineTemp + 6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  
  }else if(temperature >= baselineTemp){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1000);
}
