# 📘 Hafta 6 – LDR ile Işık Kontrolü / Week 6 – Light Control with LDR

## 🎯 Dersin Amacı (Objective)
**TR:** LDR (ışığa duyarlı direnç) ile ortam ışık seviyesini ölçüp LED’i otomatik kontrol etmek.  
**EN:** Use an LDR (photoresistor) to measure ambient light and control an LED automatically.

## 🔌 Gerekli Malzemeler (Required Components)
- 1× Arduino Uno
- 1× LDR (photoresistor)
- 1× 10kΩ resistor (for voltage divider)
- 1× LED
- 1× 220Ω resistor (for LED)
- Breadboard & jumper wires

## ⚡ Devre Bağlantısı (Circuit Wiring)
- **LDR Voltage Divider:**
  - One leg of LDR → **5V**
  - Other leg of LDR → **A0** and one leg of **10kΩ** resistor
  - Other leg of **10kΩ** resistor → **GND**
- **LED:**
  - LED anode → **pin 13** (or 9/PWM)
  - LED cathode → **220Ω** → **GND**

## 🔄 Algoritma (Algorithm / Flowchart Idea)
TR: Başla → A0’dan ışık değerini oku → Eşik ile karşılaştır → Karanlıksa LED ON / Aydınlıksa LED OFF → Tekrar  
EN: Start → Read A0 → Compare with threshold → If dark LED ON / else OFF → Repeat

## 💻 Arduino Kodu (Arduino Code with Comments)
```cpp
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
```

### 🧪 Kalibrasyon / Calibration
- Seri Monitör’de (9600 baud) **ışık–karanlık** değerlerini gözlemleyin.
- `thresholdVal` değerini ortamınıza göre 400–700 aralığında ayarlayın.

## 🖥️ Tinkercad Yol Haritası / Tinkercad Roadmap
1. [Tinkercad Circuits](https://www.tinkercad.com/circuits) → **Create new Circuit**  
2. Arduino, LDR, 10kΩ, LED ve 220Ω ekleyin.  
3. Voltaj bölücü bağlantısını A0’a kurun.  
4. Kodu kopyalayıp **Start Simulation** ile test edin.

## 💡 Not / Note
- PWM parlaklık kontrolü isterseniz LED’i PWM pinine bağlayıp LDR değerini `map()` ile 0–255’e çevirin.
