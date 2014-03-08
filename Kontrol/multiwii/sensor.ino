/* MPU6050 sensörünü okumak için gerekli fonksiyonlar
 *   MPU6050 Datasheet   : http://invensense.com/mems/gyro/documents/PS-MPU-6000A-00v3.4.pdf
 *   MPU6050 Register Map: http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Accelerometers/RM-MPU-6000A.pdf
 */
#include "Kalman.h"

// MPU6050 Register adresleri
#define MPU6050        0x68  // Aygıtın kendi adresi
#define MPU_DLPF       0x1A  // Dijital alçak geçiren filtre ayarlarının saklandığı register
#define GYRO_CONFIG    0x1B  // Jiroskop veri aralığı ayarının saklandığı register
#define ACCEL_CONFIG   0x1C  // İvmeölçer veri aralığı ayarının saklandığı register
#define ACCEL_XOUT_H   0x3B  // İvmeölçer X ekseni bilgisinin saklandığı register
#define TEMP_OUT_H     0x41  // Sıcaklık bilgisinin saklandığı register
#define GYRO_XOUT_H    0x43  // Jiroskop X ekseni bilgisinin saklandığı register
#define MPU_USER_CTRL  0x6A  // FIFO ve I2C ayarlarının saklandığı register
#define MPU_PWR_MGMT1  0x6B  // Güç modu ve saat kaynağı ayarlarının saklandığı register

// Sabitler
const float kAccelScale = 8193; // İvmeölçer sabiti
const float kGyroScale = 65.5; // Jiroskop sabiti
const float kTempScale = 36.53; // Sıcaklık sensörü sabiti

// Okunan sensör verilerinin kaydedileceği değişkenler
float ax, ay, az, temp, gx, gy, gz;

// Derece cinsinden açılar
float acc_angle_x, acc_angle_y;

// Kalman objeleri
Kalman kalman_x;
Kalman kalman_y;

// I2C den gelen verilerin geçici olarak kaydedileceği dizi
byte buffer[14];

// MPU6050 başlangıç ayarlarını yapar.
void mpuConfig() {
  #ifdef DEBUG
  Serial.println("Configuring MPU6050");
  #endif

  // Jiroskop aralığı : +-500 d/s
  writeTo(MPU6050, GYRO_CONFIG, 0x08);
  // İvmeölçer aralığı : +-4g
  writeTo(MPU6050, ACCEL_CONFIG, 0x08);
  // Saat kaynağı dahili 8MHz osilatör. Sürekli çalışma moduna ayarla.
  writeTo(MPU6050, MPU_PWR_MGMT1, 0x00);
  // Dijital Filtre : 
  //   İVMEÖLÇER  : Bandwidth = 44Hz - Delay = 4.9ms
  //   JİROSKOP   : Bandwidth = 42Hz - Delay = 4.8ms
  writeTo(MPU6050, MPU_DLPF, 0x03);
}

// Her sensörün tüm eksenlerini okur.
void readAllSensors()
{
  readFrom(MPU6050, ACCEL_XOUT_H, 14); // 'ACCEL_XOUT_H' registerından başlayarak 14 bytelık veri oku.
  
  ax = (float)(buffer[0] << 8 | buffer[1]) / kAccelScale; // İvmeölçer X ekseni
  ay = (float)(buffer[2] << 8 | buffer[3]) / kAccelScale; // İvmeölçer Y ekseni
  az = (float)(buffer[4] << 8 | buffer[5]) / kAccelScale; // İvmeölçer Z ekseni
  gx = (float)(buffer[8] << 8 | buffer[9]) / kGyroScale; // Jiroskop X ekseni
  gy = (float)(buffer[10] << 8 | buffer[11]) / kGyroScale; // Jiroskop Y ekseni
  gz = (float)(buffer[12] << 8 | buffer[13]) / kGyroScale; // Jiroskop Z ekseni
  temp =  (float)(buffer[6] << 8 | buffer[7]) / 340 + kTempScale; // Sıcaklık
  
  #ifdef DEBUG
  // Debug modunda ölçülen değerleri yazdır
  /*
  Serial.print("AX : ");
  Serial.print(ax);
  Serial.print(" | AY : ");
  Serial.print(ay);
  Serial.print(" | AZ : ");
  Serial.print(az);
  Serial.print(" | GX : ");
  Serial.print(gx);
  Serial.print(" | GY : ");
  Serial.print(gy);
  Serial.print(" | GZ : ");
  Serial.print(gz);
  Serial.print(" | Temp : ");
  Serial.println(temp);
  */
  #endif
}

// Kalman açılarını girilen değerlere eşitle.
void setKalmanAngle(int x, int y) {
  kalman_x.setAngle(x);
  kalman_y.setAngle(y);
}

// Kalman filtresinden geçirilmiş X açısı değerini çekmek için kullanılır.
float getFilteredX() {
  acc_angle_x = (atan2(ax,az)+PI)*RAD_TO_DEG;
  return kalman_x.getAngle(acc_angle_x,gx,(float)(micros() - timer));
}

// Kalman filtresinden geçirilmiş Y açısı değerini çekmek için kullanılır.
float getFilteredY() {
  acc_angle_y = (atan2(ay,az)+PI)*RAD_TO_DEG;
  return kalman_y.getAngle(acc_angle_y,gy,(float)(micros() - timer));
}

// Adresi belirtilen aygıtın belirtilen registerına verilen değeri kaydeder.
void writeTo(int device_address, byte register_address, byte value) 
{
  Wire.beginTransmission(device_address); // Aygıtla haberleşmeyi başlat.
  Wire.write(register_address);           // Register adresini gönder.
  Wire.write(value);                      // Yazılacak değeri gönder.
  Wire.endTransmission();                 // Haberleşmeyi bitir.
}

// Adresi belirtilen aygıtın belirtilen registerından verilen sayı kadar byte okur.
void readFrom(int device_address, byte address, int count)
{
  Wire.beginTransmission(device_address); // Aygıtla haberleşmeyi başlat.
  Wire.write(address);                    // Register adresini gönder.
  Wire.endTransmission();                 // Haberleşmeyi bitir.
  
  Wire.beginTransmission(device_address);  // Haberleşmeyi başlat.
  Wire.requestFrom(device_address, count); // Belirtilen sayı kadar byte iste.
  
  // I2C kanalında bulunan bütün veriyi oku ve 'buffer' registerına kaydet.
  int i = 0; // Okunan byteları sayacak değişken
  while(Wire.available())
  {
    buffer[i] = Wire.read();
    i++;
  }
  Wire.endTransmission(); // Haberleşmeyi bitir.
}
