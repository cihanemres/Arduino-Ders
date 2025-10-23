# 📘 Hafta 8 – Servo Motor Kontrolü / Week 8 – Servo Motor Control

## 🎯 Dersin Amacı (Objective)
**TR:** Servo motorun Arduino ile belirli açılara döndürülmesini öğrenmek.  
**EN:** Learn how to control a servo motor with Arduino by rotating it to specific angles.

## 🔌 Gerekli Malzemeler (Required Components)
- 1× Arduino Uno
- 1× Servo motor (SG90 veya benzeri)
- Harici güç kaynağı (opsiyonel, çoklu servo için)
- Breadboard ve jumper kablolar

## ⚡ Devre Bağlantısı (Circuit Wiring)
- Servo **Turuncu/Sarı (Signal)** → Arduino **pin 9**
- Servo **Kırmızı (VCC)** → **5V**
- Servo **Kahverengi/Siyah (GND)** → **GND**

- <img width="772" height="329" alt="image" src="https://github.com/user-attachments/assets/9b76bcae-9c48-4484-a98d-6be8fd2459b2" />


## 🔄 Algoritma (Algorithm / Flowchart Idea)
TR: Başla → Servo 0° → Servo 90° → Servo 180° → Tekrar  
EN: Start → Servo to 0° → Servo to 90° → Servo to 180° → Repeat

## 💻 Arduino Kodu (Arduino Code with Comments)
```cpp
// Hafta 8: Servo Motor Kontrolü / Week 8: Servo Motor Control
// TR: Servo motoru 0°, 90°, 180° konumlarına döndürür.
// EN: Rotates the servo motor to 0°, 90°, and 180° positions.

#include <Servo.h>

Servo myServo;  // Servo motor nesnesi / Servo motor object

void setup() {
  myServo.attach(9);  // Servo sinyal pini pin 9
}

void loop() {
  myServo.write(0);   // 0 derece
  delay(1000);
  myServo.write(90);  // 90 derece
  delay(1000);
  myServo.write(180); // 180 derece
  delay(1000);
}
```

### 🧠 Geliştirme Fikirleri / Improvement Ideas
- TR: Potansiyometre bağlayarak servo açısını kontrol edebilirsiniz.  
- EN: Use a potentiometer to control the servo angle interactively.

## 🖥️ Tinkercad Yol Haritası / Tinkercad Roadmap
1. [Tinkercad Circuits](https://www.tinkercad.com/circuits) → **Create new Circuit**  
2. Arduino Uno + Servo motor ekleyin.  
3. Servo sinyal pinini 9’a bağlayın.  
4. Kodu kopyalayıp **Start Simulation** ile test edin.

Tinkercad Linki: https://www.tinkercad.com/things/34DT5nRCKUH-servo1?sharecode=Ifwdrod764lN0NcpqxrwvEETxuJIjRehL8gh69AF08U
