// Hafta 10: DC Motor Kontrolü / Week 10: DC Motor Control
// TR: PWM ile motor hızını arttırıp azaltır.
// EN: Ramps motor speed up and down using PWM.

const int motorPin = 9; // PWM pin connected to transistor base via 1k

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  for (int sp = 0; sp <= 255; sp += 5) {
    analogWrite(motorPin, sp);
    delay(20);
  }
  delay(500);
  for (int sp = 255; sp >= 0; sp -= 5) {
    analogWrite(motorPin, sp);
    delay(20);
  }
  delay(500);
}
