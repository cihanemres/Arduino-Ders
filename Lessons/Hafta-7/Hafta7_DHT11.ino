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
  delay(2000); // Sensor reading interval

  float humidity = dht.readHumidity();     
  float temperature = dht.readTemperature(); 

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT11 reading failed!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %	");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
}
