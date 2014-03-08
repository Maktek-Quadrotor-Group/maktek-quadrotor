// Debug modunda çalıştırmak için aktifleştirin.
#define DEBUG

// Gerekli kütüphaneler
#include <Wire.h>

static int16_t motor[4];
unsigned long timer;

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
  
  // X ve Y ekseninde kalman objelerinin başlangıç açısını 0'a eşitle.
  setKalmanAngle(0, 0);
  
  // MPU6050 ayarlarını yap.
  mpuConfig();
  
  // Kalman filtresi için zamanı hesapla.
  timer = micros();
}

void loop() {
  // Tüm sensör verileri oku.
  readAllSensors();
  
  Serial.print(getFilteredX());
  Serial.print(" - ");
  Serial.println(getFilteredY());
  
  // Kalman filtresi için zamanı hesapla.
  timer = micros();
}
