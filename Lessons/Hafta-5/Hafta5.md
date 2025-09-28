# 📘 Ders 5 – Potansiyometre ile LED Parlaklık Kontrolü / Week 5 – LED Brightness Control with Potentiometer (PWM)

## 🎯 Dersin Amacı (Objective)
**TR:** Potansiyometreden alınan analog değeri kullanarak LED’in parlaklığını PWM sinyali ile kontrol etmek.  
**EN:** Use the analog value from a potentiometer to control LED brightness via PWM.  

## 🔌 Gerekli Malzemeler (Required Components)
- 1× Arduino Uno
- 1× LED
- 1× 220Ω direnç
- 1× Potansiyometre (10kΩ)
- Breadboard ve jumper kablolar

## ⚡ Devre Bağlantısı (Circuit Wiring)
- LED (anot) → Arduino **pin 9 (PWM)**, katot → 220Ω → GND  
- Potansiyometre orta bacağı → Arduino **A0**  
- Potansiyometrenin diğer iki bacağı → **5V** ve **GND**  

## 🔄 Algoritma (Algorithm / Flowchart Idea)
**TR:** Başla → Potansiyometreden analog değer oku (0–1023) → Değeri 0–255 aralığına eşle → LED parlaklığını ayarla → Tekrar et  
**EN:** Start → Read potentiometer (0–1023) → Map to 0–255 → Set LED brightness → Repeat  
<img width="1920" height="814" alt="Cool Maimu" src="https://github.com/user-attachments/assets/edba1e61-f5f8-49ee-b8cb-06efe7447c0d" />

## 💻 Arduino Kodu (Arduino Code with Comments)
```cpp
// Ders 5: Potansiyometre ile LED Parlaklık Kontrolü / Week 5: LED Brightness Control
// TR: Potansiyometreden okunan değer ile LED parlaklığını ayarlar.
// EN: Adjusts LED brightness based on potentiometer input.

const int potPin = A0;  // Potansiyometre giriş pini / Potentiometer input pin
const int ledPin = 9;   // LED PWM çıkışı / LED PWM output pin

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin); // TR: 0–1023 değerini oku / EN: Read value 0–1023
  int brightness = map(potValue, 0, 1023, 0, 255); // TR: 0–255’e ölçekle / EN: Map to 0–255
  analogWrite(ledPin, brightness);  // TR: PWM ile LED parlaklığını ayarla / EN: Set LED brightness
  delay(10); // TR: Küçük gecikme / EN: Small delay
}
```

### 🧠 Geliştirme Fikirleri / Improvement Ideas
- TR: LED yerine bir motor sürerek hız kontrolü yapabilirsiniz.  
- EN: Replace LED with a motor to control its speed.  

## 🖥️ Tinkercad Yol Haritası / Tinkercad Roadmap
1. [Tinkercad Circuits](https://www.tinkercad.com/circuits) → **Create new Circuit**  
2. Arduino, LED, direnç ve potansiyometre ekleyin.  
3. Bağlantıları yapın, kodu kopyalayın.  
4. **Start Simulation** ile test edin.

https://www.tinkercad.com/things/d66D0U3SWhv-potpwm?sharecode=NXZUbBSVjn1xYPnNGV6Ux75yv2-uL83qzTgeinT8SXE
