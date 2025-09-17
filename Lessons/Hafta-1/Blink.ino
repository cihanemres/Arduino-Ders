// LED Blink Programı / LED Blink Program
// Bu kod, Arduino'nun 13. pinine bağlı LED'i yakıp söndürür.
// This code makes the LED connected to pin 13 blink on and off.

int ledPin = 13;  // LED’in bağlı olduğu pin / Pin number where LED is connected

void setup() {
  // setup() fonksiyonu sadece bir kez çalışır.
  // setup() function runs only once.
  pinMode(ledPin, OUTPUT);  // LED pinini çıkış (OUTPUT) olarak ayarla / set pin as OUTPUT
}

void loop() {
  // loop() fonksiyonu sürekli tekrar eder.
  // loop() function repeats forever.

  digitalWrite(ledPin, HIGH);  // LED’i yak / turn LED ON
  delay(1000);                 // 1 saniye bekle / wait 1 second (1000 ms)

  digitalWrite(ledPin, LOW);   // LED’i söndür / turn LED OFF
  delay(1000);                 // 1 saniye bekle / wait 1 second
}