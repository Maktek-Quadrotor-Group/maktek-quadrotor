// Debug modunda çalıştırmak için aktifleştirin.
#define DEBUG

// Gerekli kütüphaneler
#include <Wire.h>

void setup() {
  // Serial objesini başlat.
  // Baud Rate: 115200
  Serial.begin(115200);
  
  // Wire objesini başlat.
  // Baud Rate: 9600
  Wire.begin(9600);
  
  #ifdef DEBUG
  // Karşılama mesajı
  Serial.println("Program start");
  #endif
  
  // MPU6050 ayarlarını yap.
  mpuConfig();
}

void loop() {
  // Tüm sensör verileri oku.
  readAllSensors();
}
