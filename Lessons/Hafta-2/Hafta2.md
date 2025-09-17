# 📘 Hafta 2 – Buton Kontrollü LED / Week 2 – Button‑Controlled LED

## 🎯 Dersin Amacı (Objective)
**TR:** Bir dijital girişi (buton) okuyup, bir dijital çıkışı (LED) buna göre kontrol etmek.  
**EN:** Read a digital input (button) and control a digital output (LED) accordingly.

## 🔌 Gerekli Malzemeler (Required Components)
- 1× Arduino Uno
- 1× LED
- 1× 220Ω direnç / resistor (LED için)
- 1× Push button
- 1× 10kΩ direnç (harici pull‑down kullanmak isterseniz; biz INPUT_PULLUP kullanacağız)
- Breadboard ve jumper kablolar / breadboard & jumper wires

## ⚡ Devre Bağlantısı (Circuit Wiring)
**Seçenek A – Dahili INPUT_PULLUP (önerilir):**
- LED (anot, uzun bacak) → Arduino **pin 13**, LED (katot, kısa bacak) → **220Ω** → **GND**
- Butonun bir bacağı → **GND**
- Butonun diğer bacağı → Arduino **pin 2**
- Kodda `pinMode(buttonPin, INPUT_PULLUP);` kullanılacağı için **buton basılmadığında HIGH**, **basıldığında LOW** okunur.

  
<img width="1920" height="814" alt="buton_led" src="https://github.com/user-attachments/assets/edb92039-787d-4ab6-9a78-e15c060dc618" />

**Option B – Harici Pull‑Down (alternatif):**
- LED bağlantısı aynı.
- Butonun bir bacağı → **5V**
- Diğer bacağı → **pin 2** ve **10kΩ** ile **GND** (pull‑down)
- Bu senaryoda `pinMode(buttonPin, INPUT);` ve **basılınca HIGH** okunur.

  <img width="1920" height="814" alt="Fantabulous Curcan" src="https://github.com/user-attachments/assets/77c725c8-b3c0-489d-9105-ba1695c1abaf" />


## 🔄 Algoritma (Algorithm / Flowchart Idea)
**TR:** Başla → Buton durumunu oku → Eğer basılıysa LED ON, değilse LED OFF → Tekrar et  
**EN:** Start → Read button state → If pressed LED ON, else OFF → Repeat

## 💻 Arduino Kodu (Arduino Code with Comments)
Aşağıdaki örnek **INPUT_PULLUP** mantığıyla yazılmıştır (Seçenek A).

```cpp
// Hafta 2: Buton Kontrollü LED / Week 2: Button-Controlled LED
// TR: INPUT_PULLUP kullandığımız için buton serbestken HIGH, basılınca LOW okur.
// EN: With INPUT_PULLUP, button reads HIGH when released and LOW when pressed.

const int ledPin = 13;   // LED pin
const int buttonPin = 2; // Button pin

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Dahili pull-up aktif
}

void loop() {
  int buttonState = digitalRead(buttonPin); // HIGH: serbest, LOW: basılı

  if (buttonState == LOW) {        // TR: Basılı   EN: Pressed
    digitalWrite(ledPin, HIGH);    // LED ON
  } else {                         // TR: Serbest  EN: Released
    digitalWrite(ledPin, LOW);     // LED OFF
  }
}
```

### 🧠 Notlar / Notes
- **Zıplama (debounce):** Bazı butonlarda titreşim nedeniyle hızlı ON/OFF görülebilir. Basit bir debounce için 10–20 ms gecikme ekleyebilir veya yazılımsal debounce algoritması kullanabilirsiniz.
- **Güvenlik:** LED’i her zaman uygun bir seri dirençle sürün (220Ω–330Ω arası tipik).

---

## 🇬🇧 Quick English Summary
- Use **INPUT_PULLUP** and wire the button between **pin 2** and **GND**.
- LED anode to **pin 13**, cathode through **220Ω** to **GND**.
- Read the button and turn the LED ON when pressed (LOW), OFF otherwise.

---

## 🖥️ Tinkercad Yol Haritası / Tinkercad Roadmap
1. [Tinkercad Circuits](https://www.tinkercad.com/circuits) → **Create new Circuit**  
2. Arduino Uno, LED, 220Ω, buton ekle.  
3. Yukarıdaki bağlantıları yap, kodu kopyala.  
4. **Start Simulation** ile test et.

tinkercad link: https://www.tinkercad.com/things/9yI4efM0mYi-butonled?sharecode=nf-DKjZufShY0kxEzF6Qm5I2jzhGn-V3_hL_g3cvBKo
