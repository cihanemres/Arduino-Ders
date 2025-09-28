// Hafta 5: Potansiyometre ile LED Parlaklık Kontrolü / Week 5: LED Brightness Control
// TR: Potansiyometreden okunan değer ile LED parlaklığını ayarlar.
// EN: Adjusts LED brightness based on potentiometer input.

const int potPin = A0;  // Potansiyometre giriş pini / Potentiometer input pin
const int ledPin = 9;   // LED PWM çıkışı / LED PWM output pin

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin); // TR: 0–1023 değerini oku / EN: Read value 0–1023
  int brightness = map(potValue, 0, 1023, 0, 255); // TR: 0–255’e ölçekle / EN: Map to 0–255
  analogWrite(ledPin, brightness);  // TR: PWM ile LED parlaklığını ayarla / EN: Set LED brightness
  delay(10); // TR: Küçük gecikme / EN: Small delay
}
