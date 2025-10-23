// Hafta 8 (Gelişmiş): Potansiyometre ile Servo Kontrolü
// TR: Potansiyometreden okunan değerle servo açısını 0–180° aralığında kontrol eder.
// EN: Controls the servo angle (0–180°) based on potentiometer reading.

#include <Servo.h>

const int potPin = A0;  // Potentiometer analog input
const int servoPin = 9; // Servo signal pin

Servo s;

void setup() {
  s.attach(servoPin);
  // Optional: Serial for debugging
  Serial.begin(9600);
}

void loop() {
  int pot = analogRead(potPin);        // 0..1023
  int angle = map(pot, 0, 1023, 0, 180);
  s.write(angle);
  Serial.println(angle);
  delay(15); // small smoothing delay
}
