#include <Stepper.h>

const int motorpin = 2;  // DC motor control pin (ON/OFF)
const int stepsPerRevolution = 2048;  // For 28BYJ-48 stepper motor

// Keep your working pin order here
Stepper mystepper(stepsPerRevolution, 8, 10, 9, 11);  

void setup() {
  pinMode(motorpin, OUTPUT);      // DC Motor control pin
  mystepper.setSpeed(10);         // Set speed in RPM for stepper motor
}

void loop() {
  // Run DC motor for 0.5 sec
  digitalWrite(motorpin, HIGH);
  delay(500);
  digitalWrite(motorpin, LOW);
  delay(500);

  // Rotate stepper motor one full revolution clockwise
  mystepper.step(stepsPerRevolution);
  delay(1000);

  // Rotate stepper motor one full revolution counter-clockwise (REVERSE)
  mystepper.step(-stepsPerRevolution);
  delay(1000);
}