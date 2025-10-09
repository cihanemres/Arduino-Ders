# 📘 Hafta 7 – DHT11 ile Sıcaklık & Nem Ölçümü / Week 7 – Temperature & Humidity with DHT11

## 🎯 Dersin Amacı (Objective)
**TR:** DHT11 sensörü ile ortam sıcaklığı ve nem değerlerini okumak ve seri monitörde görüntülemek.  
**EN:** Learn how to use the DHT11 sensor to read temperature and humidity values and display them on the Serial Monitor.

## 🔌 Gerekli Malzemeler (Required Components)
- 1× Arduino Uno
- 1× DHT11 sensör modülü veya çıplak sensör (3 pin/4 pin)
- Breadboard ve jumper kablolar

## ⚡ Devre Bağlantısı (Circuit Wiring)
- DHT11 **VCC** → 5V
- DHT11 **GND** → GND
- DHT11 **DATA** → Arduino **pin 2**

## 🔄 Algoritma (Algorithm / Flowchart Idea)
TR: Başla → Sensörden sıcaklık ve nem oku → Seri Monitör’e yaz → Tekrar et  
EN: Start → Read temperature & humidity → Print on Serial Monitor → Repeat

## 💻 Arduino Kodu (Arduino Code with Comments)
```cpp
// Hafta 7: DHT11 ile Sıcaklık ve Nem Ölçümü / Week 7: Temperature & Humidity with DHT11
// TR: Sensörden sıcaklık ve nem değerlerini okur ve seri monitöre yazar.
// EN: Reads temperature and humidity values from DHT11 and prints them to Serial Monitor.

#include "DHT.h"

#define DHTPIN 2       // DHT11 data pin
#define DHTTYPE DHT11  // Sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT11 Sensor Test Başladı...");
}

void loop() {
  delay(2000); // Sensör okuma aralığı

  float humidity = dht.readHumidity();     // Nem
  float temperature = dht.readTemperature(); // Sıcaklık (Celsius)

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT11 verisi okunamıyor!");
    return;
  }

  Serial.print("Nem: ");
  Serial.print(humidity);
  Serial.print(" %	");

  Serial.print("Sıcaklık: ");
  Serial.print(temperature);
  Serial.println(" *C");
}
```

### 🧠 Geliştirme Fikirleri / Improvement Ideas
- TR: Ekran (LCD/OLED) ekleyerek değerleri gösterebilirsiniz.  
- EN: Display values on an LCD or OLED for real-time monitoring.

## 🖥️ Tinkercad Yol Haritası / Tinkercad Roadmap
1. [Tinkercad Circuits](https://www.tinkercad.com/circuits) → **Create new Circuit**  
2. Arduino Uno + DHT11 sensör ekleyin.  
3. DATA pinini 2 numaralı pine bağlayın.  
4. Kodu kopyalayıp **Start Simulation** ile çalıştırın.
