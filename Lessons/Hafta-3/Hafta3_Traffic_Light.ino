// Hafta 3: Trafik Lambası Simülasyonu / Week 3: Traffic Light Simulation
// TR: 3 LED'i trafik lambası sırasına göre yakar.
// EN: Drives 3 LEDs in a traffic-light sequence.

const int RED_PIN    = 8;
const int YELLOW_PIN = 9;
const int GREEN_PIN  = 10;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  allOff();
}

void loop() {
  // Red (3 s)
  setLights(HIGH, LOW, LOW);
  delay(3000);

  // Yellow (1 s)
  setLights(LOW, HIGH, LOW);
  delay(1000);

  // Green (3 s)
  setLights(LOW, LOW, HIGH);
  delay(3000);

  // Yellow (1 s) transition
  setLights(LOW, HIGH, LOW);
  delay(1000);
}

void setLights(int r, int y, int g) {
  digitalWrite(RED_PIN, r);
  digitalWrite(YELLOW_PIN, y);
  digitalWrite(GREEN_PIN, g);
}

void allOff() {
  setLights(LOW, LOW, LOW);
}
