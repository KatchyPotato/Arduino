int notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  if (keyVal > 1020) {                 
    tone(8, notes[0]);
  }else if (keyVal > 1000 && keyVal <= 1010) {  
    tone(8, notes[1]);
  }else if (keyVal > 950 && keyVal <= 990) {   
    tone(8, notes[2]);
  }else if (keyVal > 500 && keyVal <= 550) {    
    tone(8, notes[3]);
  }else {
    noTone(8);
  }                       
}

// ChatGPT for help with debugging



