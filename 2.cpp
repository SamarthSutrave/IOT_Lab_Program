const int redPin = 8;
const int yellowPin = 9;
const int greenPin = 10;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void setLight(int redState, int yellowState, int greenState, int duration) {
  digitalWrite(redPin, redState);
  digitalWrite(yellowPin, yellowState);
  digitalWrite(greenPin, greenState);
  delay(duration);
}

void loop() {
  setLight(HIGH, LOW, LOW, 1000);
  setLight(LOW, LOW, HIGH, 1000);
  setLight(LOW, HIGH, LOW, 1000);
}