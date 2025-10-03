// Hafta 6: LDR ile Işık Kontrolü / Week 6: Light Control with LDR
// TR: LDR'den okunan değere göre LED'i otomatik yakar/söndürür.
// EN: Turns LED on/off based on LDR reading.

const int ldrPin = A0;   // LDR divider output
const int ledPin = 13;   // LED pin (or 9/PWM for analog brightness)
int thresholdVal = 600;  // Adjust for your environment (0-1023)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  if (ldrValue < thresholdVal) {
    digitalWrite(ledPin, HIGH); // Dark → LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Bright → LED OFF
  }

  delay(50);
}
