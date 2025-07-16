void setup() {
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char letter = Serial.read();

    if (letter == '1') {
      digitalWrite(3, HIGH);
      Serial.println("The LED is ON");
    }
    else if (letter == '0') {
      digitalWrite(3, LOW);
      Serial.println("The LED is OFF");
    }
    else {
      Serial.println("Invalid Input");
    }
    delay(200);
  }
}