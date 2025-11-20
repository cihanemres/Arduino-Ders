# 🔧 L298N ile DC Motor Yön Kontrolü (İleri/Geri)

## Bağlantılar (Tek Motor - A Kanalı)
- **ENA** → Arduino **PWM pin 9**
- **IN1** → Arduino **7**
- **IN2** → Arduino **6**
- **OUT1/OUT2** → Motor uçları
- **+12V/+9V VIN** → Harici besleme (**motor** için)
- **GND** → Harici besleme GND
- **Ortak Toprak:** Arduino **GND** ile L298N **GND** mutlaka ortak olmalı.

> Not: Kart üzerindeki **EN** jumper'ı takılıysa ENA sabit HIGH olur; hız kontrolü için jumper'ı çıkarın ve ENA'yı PWM pine bağlayın.

## Kullanım
- `forward(hız)` ve `reverse(hız)` fonksiyonları ile yön ve hız kontrol edilir (0–255).
- `stopMotor()` motoru serbest bırakır (coast). Aktif fren için `IN1=IN2=HIGH` uygulanabilir.
