# 🧪 Hafta 1 – LED Yakma (Blink) Ders Notu / Week 1 – LED Blink Lesson Note

Bu dosyada, Arduino ile LED yakma (Blink) projesi için hem Türkçe hem de İngilizce ders notları bulunmaktadır.  
This file contains lesson notes in Turkish and English for the LED blink project with Arduino.

---

## 🎯 Dersin Amacı / Objective

**TR:** Arduino’nun dijital çıkış pinlerini kullanarak bir LED’in yanıp sönmesini sağlamak.  
**EN:** To make an LED blink using Arduino’s digital output pins.

---

## 🔌 Gerekli Malzemeler / Required Components

* 1 × Arduino Uno  
* 1 × LED  
* 1 × 220 Ω direnç / resistor  
* 1 × Breadboard  
* Jumper kablolar / jumper wires

---

## ⚡ Devre Bağlantısı / Circuit Connection

* LED’in uzun bacağı (anot / **anode**) → Arduino **pin 13**  
* LED’in kısa bacağı (katot / **cathode**) → Direnç → Arduino **GND**

---

## 🔄 Algoritma / Algorithm (Flowchart Idea)

**TR:** Başla → LED’i yak → 1 saniye bekle → LED’i söndür → 1 saniye bekle → Tekrar et  
**EN:** Start → Turn LED ON → Wait 1 s → Turn LED OFF → Wait 1 s → Repeat

---

## 💻 Arduino Kodu / Arduino Code with Comments

Kod dosyası `Blink.ino` olarak bu klasörde yer almaktadır. Aşağıda kodun kısa bir görünümü bulunmaktadır:

```cpp
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
```

---

## 📝 Açıklamalar / Explanations

**TR:**

* `pinMode()` → Pinin giriş (INPUT) mi çıkış (OUTPUT) mı olduğunu belirler.  
* `digitalWrite()` → Pini HIGH (1) = elektrik var veya LOW (0) = elektrik yok yapar.  
* `delay(ms)` → Kodun belirtilen süre kadar beklemesini sağlar (ms cinsinden).

**EN:**

* `pinMode()` → Defines if the pin will be used as **INPUT** or **OUTPUT**.  
* `digitalWrite()` → Sets the pin HIGH (1 = ON) or LOW (0 = OFF).  
* `delay(ms)` → Stops the code for the given time in milliseconds.

👉 Bu kod sayesinde LED **1 saniye yanar – 1 saniye söner** ve döngü sürekli devam eder.  
👉 With this code, the LED stays **ON for 1 second – OFF for 1 second**, repeating forever.