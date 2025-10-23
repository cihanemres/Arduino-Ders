// Hafta 8: Servo Motor Kontrolü / Week 8: Servo Motor Control
// TR: Servo motoru 0°, 90°, 180° konumlarına döndürür.
// EN: Rotates the servo motor to 0°, 90°, and 180° positions.

#include <Servo.h>

Servo myServo;  

void setup() {
  myServo.attach(9);  // Attach servo signal to pin 9
}

void loop() {
  myServo.write(0);   // Move to 0 degrees
  delay(1000);
  myServo.write(90);  // Move to 90 degrees
  delay(1000);
  myServo.write(180); // Move to 180 degrees
  delay(1000);
}
