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
ldr.ino: <img width="1920" height="814" alt="ldr" src="https://github.com/user-attachments/assets/cb1cac13-08ba-4677-a209-6f51af9510e2" />
ldr_pwm.ino: <img width="1920" height="814" alt="ldr2" src="https://github.com/user-attachments/assets/7436b2dc-e7cc-4998-924e-d0258a5af6f9" />


## 🔄 Algoritma (Algorithm / Flowchart Idea)
TR: Başla → A0’dan ışık değerini oku → Eşik ile karşılaştır → Karanlıksa LED ON / Aydınlıksa LED OFF → Tekrar  
EN: Start → Read A0 → Compare with threshold → If dark LED ON / else OFF → Repeat

## 💻 Arduino Kodu (Arduino Code with Comments) ldr_pwm.ino
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
## 💻 Arduino Kodu (Arduino Code with Comments) ldr.ino
```cpp
// Hafta 6 (PWM versiyonu): LDR ile LED Parlaklık Kontrolü
// TR: LDR değerini okuyarak LED parlaklığını PWM ile ayarlar.
// EN: Reads LDR value and adjusts LED brightness using PWM.

const int ldrPin = A0;   // LDR divider output
const int ledPin = 9;    // LED on PWM pin

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin); // 0-1023
  Serial.println(ldrValue);

  // Map LDR value to PWM range
  int brightness = map(ldrValue, 0, 1023, 255, 0);  //tinkercad üzerinde denemek için int brightness = map(ldrValue, 0, 679, 255, 0); olarak değiştirin.
  analogWrite(ledPin, brightness);

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
tinkercad bağlantısı:https://www.tinkercad.com/things/f4wH9OBCzcw-ldr?sharecode=FVADT3Him08h9Ki9Js7h1CJM2a9lRBb_8isVBjpVOos

ldr_pwm tinkercad bağlantısı: https://www.tinkercad.com/things/j5OyaTooDAK-ldr2?sharecode=tNrSoJ5N0D1GjUhUX7aFoZToEtzhxzDBqyQikkNLhmQ
## 💡 Not / Note
- PWM parlaklık kontrolü isterseniz LED’i PWM pinine bağlayıp LDR değerini `map()` ile 0–255’e çevirin.
