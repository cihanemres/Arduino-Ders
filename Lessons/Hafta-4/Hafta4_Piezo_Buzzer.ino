// Hafta 4: Piezo Buzzer ile Ses Çıkışı / Week 4: Piezo Buzzer Sound Output
// TR: 440 Hz'lik basit bir ton üretir, 0.5 saniye çalar, 0.5 saniye durur.
// EN: Generates a 440 Hz tone, plays for 0.5s, pauses for 0.5s.

const int buzzerPin = 8; // Piezo buzzer pin

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 440, 500);  // TR: 440 Hz çal (500 ms) | EN: Play 440 Hz for 500 ms
  delay(700);                 // TR: Küçük bir duraklama | EN: Small pause
}
