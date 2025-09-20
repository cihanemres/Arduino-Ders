# 🚦 Hafta 3 – Trafik Lambası Simülasyonu / Week 3 – Traffic Light Simulation

## 🎯 Dersin Amacı (Objective)
**TR:** Zamanlama ve sıralama yapılarıyla üç LED’i trafik lambası mantığında kontrol etmek.  
**EN:** Control three LEDs in a traffic-light sequence using timing and ordering.

## 🔌 Gerekli Malzemeler (Required Components)
- 1× Arduino Uno
- 3× LED (Kırmızı, Sarı, Yeşil) / (Red, Yellow, Green)
- 3× 220Ω direnç / resistors (one for each LED)
- Breadboard ve jumper kablolar / breadboard & jumper wires

## ⚡ Devre Bağlantısı (Circuit Wiring)
- Kırmızı LED (anot) → **pin 8**, (katot) → **220Ω** → **GND**
- Sarı LED (anot) → **pin 9**, (katot) → **220Ω** → **GND**
- Yeşil LED (anot) → **pin 10**, (katot) → **220Ω** → **GND**

**Not / Note:** LED’in uzun bacağı **anot ( + )**, kısa bacağı **katot ( – )**’dur. Katodu dirence, dirençten GND’ye bağlayın.

## 🔄 Algoritma (Algorithm / Flowchart Idea)
**TR:** Başla → Kırmızı ON (3 sn) → Sarı ON (1 sn) → Yeşil ON (3 sn) → Sarı ON (1 sn) → Tekrar  
**EN:** Start → Red ON (3s) → Yellow ON (1s) → Green ON (3s) → Yellow ON (1s) → Repeat

## 💻 Arduino Kodu (Arduino Code with Comments)
Aşağıdaki örnek basit **delay()** tabanlı zamanlama kullanır.

```cpp
// Hafta 3: Trafik Lambası Simülasyonu / Week 3: Traffic Light Simulation
// TR: 3 LED'i trafik lambası sırasına göre yakar.
const int RED_PIN    = 8;
const int YELLOW_PIN = 9;
const int GREEN_PIN  = 10;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  allOff();
}

void loop() {
  // Kırmızı (3 sn) / Red (3 s)
  setLights(HIGH, LOW, LOW);
  delay(3000);

  // Sarı (1 sn) / Yellow (1 s)
  setLights(LOW, HIGH, LOW);
  delay(1000);

  // Yeşil (3 sn) / Green (3 s)
  setLights(LOW, LOW, HIGH);
  delay(3000);

  // Sarı (1 sn) / Yellow (1 s) - geçiş
  setLights(LOW, HIGH, LOW);
  delay(1000);
}

void setLights(int r, int y, int g) {
  digitalWrite(RED_PIN, r);
  digitalWrite(YELLOW_PIN, y);
  digitalWrite(GREEN_PIN, g);
}

void allOff() {
  setLights(LOW, LOW, LOW);
}
```

### 🧠 Geliştirme Fikri / Improvement Idea
**TR:** `delay()` yerine `millis()` ile **bloklamayan zamanlama** kurabilir, aynı anda buton okuma gibi ek özellikler ekleyebilirsiniz.  
**EN:** Replace `delay()` with `millis()` for **non-blocking timing** to add inputs (e.g., a pedestrian button).

---

## 🇬🇧 Quick English Summary
- Wire LEDs to pins 8 (Red), 9 (Yellow), 10 (Green) with 220Ω resistors to GND.  
- Use the provided code to cycle Red → Yellow → Green → Yellow with delays.

---

## 🖥️ Tinkercad Yol Haritası / Tinkercad Roadmap
1. [Tinkercad Circuits](https://www.tinkercad.com/circuits) → **Create new Circuit**  
2. Arduino Uno + 3 LED + 3×220Ω ekleyin.  
3. Bağlantıları yapın ve kodu kopyalayın.  
4. **Start Simulation** ile test edin.
