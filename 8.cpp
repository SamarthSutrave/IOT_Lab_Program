// Pin assignments
const int trigPin = 10;
const int echoPin = 9;
const int buzzerPin = 8;

// Distance threshold in cm
const int thresholdDistance = 20;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  float distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2; // Convert to cm

  // Print distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check distance
  if (distance > 0 && distance < thresholdDistance) {
    digitalWrite(buzzerPin, HIGH); // Object too close
  } else {
    digitalWrite(buzzerPin, LOW);  // Safe
  }

  delay(200); // Small delay to stabilize readings
}