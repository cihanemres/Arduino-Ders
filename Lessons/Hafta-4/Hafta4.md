# 📘 Hafta 4 – Piezo Buzzer ile Ses Çıkışı / Week 4 – Piezo Buzzer Sound Output

## 🎯 Dersin Amacı (Objective)
**TR:** Arduino ile ses üreten bir devre kurarak dijital pin üzerinden buzzer kontrolünü öğrenmek.  
**EN:** Learn how to generate sound using a piezo buzzer controlled by an Arduino digital pin.  

## 🔌 Gerekli Malzemeler (Required Components)
- 1× Arduino Uno
- 1× Piezo buzzer (aktif ya da pasif)
- 1× 100Ω–220Ω direnç (opsiyonel, ses yüksekliğini sınırlamak için)
- Breadboard ve jumper kablolar

## ⚡ Devre Bağlantısı (Circuit Wiring)
- Piezo buzzer (+) → Arduino **pin 8**
- Piezo buzzer (–) → **GND**
<img width="1920" height="814" alt="Cool Maimu-Uusam" src="https://github.com/user-attachments/assets/414eed44-4613-405e-865a-2195b1dcb66f" />

Not: Pasif buzzer kullanıyorsanız `tone()` fonksiyonuyla frekans ayarlayabilirsiniz.

## 🔄 Algoritma (Algorithm / Flowchart Idea)
**TR:** Başla → Buzzer’a 440 Hz ton gönder (0,5 sn) → Bekle (0,5 sn) → Tekrar  
**EN:** Start → Play 440 Hz tone (0.5 s) → Pause (0.5 s) → Repeat  

## 💻 Arduino Kodu (Arduino Code with Comments)
```cpp
// Hafta 4: Piezo Buzzer ile Ses Çıkışı / Week 4: Piezo Buzzer Sound Output
// TR: 440 Hz'lik basit bir ton üretir, 0.5 saniye çalar, 0.5 saniye durur.
// EN: Generates a 440 Hz tone, plays for 0.5s, pauses for 0.5s.

const int buzzerPin = 8; // Piezo buzzer pin

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 440, 500);  // TR: 440 Hz çal (500 ms) | EN: Play 440 Hz for 500 ms
  delay(700);                 // TR: Küçük bir duraklama | EN: Small pause
}
```

### 🧠 Geliştirme Fikirleri / Improvement Ideas
- TR: Birden fazla frekans çalarak küçük melodiler oluşturabilirsiniz.  
- EN: Try combining different frequencies to create simple melodies.  

## 🖥️ Tinkercad Yol Haritası / Tinkercad Roadmap
1. [Tinkercad Circuits](https://www.tinkercad.com/circuits) → **Create new Circuit**  
2. Arduino Uno + Piezo buzzer ekleyin.  
3. Yukarıdaki bağlantıları yapın.  
4. Kodu kopyalayıp **Start Simulation** ile çalıştırın.

https://www.tinkercad.com/things/6GCa8sbkSF0-buzzer?sharecode=C4y7n9QwyiSsA76IDGufYK-ebjbBIpq-ilj6PSFUd30
