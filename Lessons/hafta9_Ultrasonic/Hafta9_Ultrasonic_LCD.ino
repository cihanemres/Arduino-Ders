// Hafta 9 (Gelişmiş): Ultrasonik + I2C LCD (16x2)
// TR: HC-SR04 mesafeyi I2C LCD'de gösterir.
// EN: Shows HC-SR04 distance on a 16x2 I2C LCD.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 9;
const int echoPin = 8;

// I2C adresi çoğunlukla 0x27 (bazı modüllerde 0x3F)
// Gerekirse adresi değiştirin.
LiquidCrystal_I2C lcd(0x27, 16, 2);

long readUltrasonicCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // µs, 30ms timeout
  if (duration == 0) return -1;

  long distanceCm = duration / 58; // ~cm (20°C için)
  return distanceCm;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();          // I2C LCD başlat
  lcd.backlight();     // arka ışık aç
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HC-SR04 Hazir");
  lcd.setCursor(0, 1);
  lcd.print("I2C LCD 16x2");
  delay(1500);

  // Başlık sabit kalsın
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mesafe:");
}

void loop() {
  long d = readUltrasonicCM();

  lcd.setCursor(0, 1);
  if (d < 0) {
    // Önceki yazıyı silmek için satırı boşlukla doldur
    lcd.print("Timeout!        ");
  } else {
    // "xxx cm" yaz, kalan kısmı boşlukla temizle
    lcd.print("                ");     // satırı temizlemenin pratik yolu
    lcd.setCursor(0, 1);
    lcd.print(d);
    lcd.print(" cm");
  }

  delay(500);
}
