// Hafta 6 (PWM versiyonu): LDR ile LED Parlaklık Kontrolü
// TR: LDR değerini okuyarak LED parlaklığını PWM ile ayarlar.
// EN: Reads LDR value and adjusts LED brightness using PWM.

const int ldrPin = A0;   // LDR divider output
const int ledPin = 9;    // LED on PWM pin

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin); // 0-1023
  Serial.println(ldrValue);

  // Map LDR value to PWM range
  int brightness = map(ldrValue, 0, 1023, 255, 0);
  analogWrite(ledPin, brightness);

  delay(50);
}
