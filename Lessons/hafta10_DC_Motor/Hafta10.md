# 📘 Hafta 10 – DC Motor Kontrolü / Week 10 – DC Motor Control

## 🎯 Dersin Amacı (Objective)
**TR:** Arduino ile bir DC motorun hızını PWM kullanarak kontrol etmek.  
**EN:** Control a DC motor’s speed using PWM with Arduino.

## 🔌 Gerekli Malzemeler (Required Components)
- 1× Arduino Uno  
- 1× DC motor (3–9V)
- 1× NPN transistör (2N2222/BC337 vb.) **veya** motor sürücü (L298N/L293D)
- 1× Diyot (1N4007; motor ters EMF için)
- 1× 1kΩ direnç (transistör baz direnci)
- Harici güç kaynağı (motor için 5–9V; **Arduino ile ortak GND**)
- Breadboard ve jumper kablolar

## ⚡ Devre Bağlantısı (Circuit Wiring – Transistörlü Basit Sürme)
- **PWM sinyali**: Arduino **pin 9** → **1kΩ** → Transistör **Base**
- Transistör **Emitter** → **GND**
- Transistör **Collector** → Motorun bir ucu
- Motorun diğer ucu → **Harici +V (ör. 6V)**
- **Diyot**: Motor uçlarına paralel **(katot +V tarafına, anot transistör tarafına)** (flyback koruması)
- **Ortak Toprak**: Arduino GND ile harici güç GND **birleştirilmeli**

> Not: Yüksek akımlarda transistör yerine **L298N/L293D** gibi sürücüler tercih edin.

## 🔄 Algoritma (Algorithm / Flowchart Idea)
TR: Başla → PWM değerini arttır (hızlan) → Bekle → PWM değerini azalt (yavaşla) → Tekrar  
EN: Start → Increase PWM (speed up) → Wait → Decrease PWM (slow down) → Repeat

## 💻 Arduino Kodu (Arduino Code with Comments)
```cpp
// Hafta 10: DC Motor Kontrolü / Week 10: DC Motor Control
// TR: PWM ile motor hızını arttırıp azaltır.
// EN: Ramps motor speed up and down using PWM.

const int motorPin = 9; // PWM pin connected to transistor base via 1k

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Speed up
  for (int sp = 0; sp <= 255; sp += 5) {
    analogWrite(motorPin, sp);
    delay(20);
  }
  delay(500);

  // Slow down
  for (int sp = 255; sp >= 0; sp -= 5) {
    analogWrite(motorPin, sp);
    delay(20);
  }
  delay(500);
}
```

### 🧠 Geliştirme Fikirleri / Improvement Ideas
- TR: **L298N** motor sürücü ile ileri/geri yön kontrolü ekleyin.  
- TR: Potansiyometre ile hız kontrolü yapın (`analogRead()` → `map()` → `analogWrite()`).  
- EN: Use an **L298N** driver for direction control; add a potentiometer for interactive speed.

## 🖥️ Tinkercad Yol Haritası / Tinkercad Roadmap
1. [Tinkercad Circuits](https://www.tinkercad.com/circuits) → **Create new Circuit**  
2. Arduino + DC motor + transistör + diyot devresini kurun (veya L298N).  
3. PWM pinini 9’a bağlayın, ortak GND’yi unutmayın.  
4. Kodu kopyalayıp **Start Simulation** ile test edin.
