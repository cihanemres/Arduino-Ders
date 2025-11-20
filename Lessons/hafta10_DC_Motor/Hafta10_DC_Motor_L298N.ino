// Hafta 10 (Gelişmiş): L298N ile DC Motor İleri/Geri Yön Kontrolü
// TR: L298N sürücü kartı ile motoru ileri/geri döndürür, PWM ile hız kontrolü sağlar.
// EN: Controls DC motor direction (forward/reverse) using L298N and PWM speed control.

// L298N bağlantıları (tek motor - A kanalı):
// ENA -> Arduino PWM pin (ör. 9)
// IN1 -> Arduino dijital pin (ör. 7)
// IN2 -> Arduino dijital pin (ör. 6)
// Motor uçları -> OUT1 ve OUT2
// L298N 12V/9V VIN -> Harici besleme (+), GND -> Ortak toprak
// Arduino GND ile L298N GND mutlaka ortak olmalı.

const int ENA = 9;  // PWM speed control
const int IN1 = 7;  // Direction
const int IN2 = 6;  // Direction

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  stopMotor();
}

void loop() {
  // Forward ramp
  for (int sp = 0; sp <= 255; sp += 15) {
    forward(sp);
    delay(80);
  }
  delay(500);

  // Brake/stop
  stopMotor();
  delay(500);

  // Reverse ramp
  for (int sp = 0; sp <= 255; sp += 15) {
    reverse(sp);
    delay(80);
  }
  delay(500);

  stopMotor();
  delay(800);
}

void forward(int speedVal) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, constrain(speedVal, 0, 255));
}

void reverse(int speedVal) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, constrain(speedVal, 0, 255));
}

void stopMotor() {
  // Hız kesme (coast) için ENA=0; aktif fren isterseniz IN1=IN2=HIGH yapabilirsiniz
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}
