// Hafta 9: Ultrasonik Mesafe Ölçümü / Week 9: Ultrasonic Distance Measurement
// TR: HC-SR04 ile mesafeyi cm cinsinden hesaplar ve seri monitöre yazar.
// EN: Calculates distance in cm using HC-SR04 and prints it to Serial Monitor.

const int trigPin = 9;
const int echoPin = 8;

long readUltrasonicCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // timeout
  if (duration == 0) return -1;

  long distanceCm = duration / 58; // ~ cm
  return distanceCm;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  long d = readUltrasonicCM();
  if (d < 0) {
    Serial.println("Timeout!");
  } else {
    Serial.print("Distance: ");
    Serial.print(d);
    Serial.println(" cm");
  }
  delay(200);
}
