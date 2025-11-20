# 📘 Hafta 9 – Ultrasonik Mesafe Ölçümü / Week 9 – Ultrasonic Distance Measurement (HC-SR04)

## 🎯 Dersin Amacı (Objective)
**TR:** HC-SR04 ultrasonik sensör ile mesafeyi ölçmek ve seri monitörde görüntülemek.  
**EN:** Measure distance using the HC-SR04 ultrasonic sensor and display it on the Serial Monitor.

## 🔌 Gerekli Malzemeler (Required Components)
- 1× Arduino Uno
- 1× HC-SR04 ultrasonik sensör
- Breadboard ve jumper kablolar

## ⚡ Devre Bağlantısı (Circuit Wiring)
- **VCC** → 5V  
- **GND** → GND  
- **TRIG** → Arduino **pin 9**  
- **ECHO** → Arduino **pin 8**

> Not: HC-SR04 5V ile çalışır; Arduino Uno dijital pinleri de 5V uyumludur.

## 🔄 Algoritma (Algorithm / Flowchart Idea)
TR: Başla → TRIG’e 10µs darbe gönder → ECHO süresini ölç → Süreden mesafeyi hesapla → Yazdır → Tekrar  
EN: Start → Send 10µs pulse on TRIG → Measure ECHO pulse length → Compute distance → Print → Repeat

## 💻 Arduino Kodu (Arduino Code with Comments)
```cpp
// Hafta 9: Ultrasonik Mesafe Ölçümü / Week 9: Ultrasonic Distance Measurement
// TR: HC-SR04 ile mesafeyi cm cinsinden hesaplar ve seri monitöre yazar.
// EN: Calculates distance in cm using HC-SR04 and prints it to Serial Monitor.

const int trigPin = 9;
const int echoPin = 8;

long readUltrasonicCM() {
  // TRIG'i temizle
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // 10 mikrosaniyelik tetik darbesi
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // ECHO darbesinin süresini ölç (mikrosaniye)
  long duration = pulseIn(echoPin, HIGH, 30000); // 30 ms timeout ~ 5 m
  if (duration == 0) return -1; // zaman aşımı

  // Ses hızı ~343 m/s → cm için duration/58 yaklaşıklığı
  long distanceCm = duration / 58;
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
    Serial.println("Olcum zaman asimi!");
  } else {
    Serial.print("Mesafe: ");
    Serial.print(d);
    Serial.println(" cm");
  }
  delay(200);
}
```

### 🧠 İyileştirme Fikirleri / Improvement Ideas
- TR: Titreşimi azaltmak için birkaç ölçümü ortalayın (moving average).  
- TR: Belirli mesafenin altındaysa LED veya buzzer ile uyarı verin.  
- EN: Average multiple samples for stability; add LED/buzzer alert under a threshold.

## 🖥️ Tinkercad Yol Haritası / Tinkercad Roadmap
1. [Tinkercad Circuits](https://www.tinkercad.com/circuits) → **Create new Circuit**  
2. Arduino + HC-SR04 ekleyin, TRIG=9 / ECHO=8 bağlayın.  
3. Kodu kopyalayıp **Start Simulation** ile çalıştırın.
