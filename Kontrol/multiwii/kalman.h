/* Ayrık kalman filtresi
 *   TKJ Elecktronnics makalesi: http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it
 */
#ifndef _Kalman_h
#define _Kalman_h

// Kalman sınıfı başlangıcı
class Kalman {
  public:
  // Constructor: Parametreleri ve başlanıç değerlerini ayarla.
  Kalman() {
    // Filtre parametreleri
    q_angle = 0.001;
    q_bias = 0.003;
    r_measure = 0.03;

    bias = 0; // Bias'ı sıfırla
    P[0][0] = 0; // Bias'ı sıfır farz ettiğimize göre başlangıç açısını biliyoruz. NOT: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
    P[0][1] = 0;
    P[1][0] = 0;
    P[1][1] = 0;
  };
  
  // Açı derece, değişim derece/derece ve delta zaman saniye cinsinden olmalı.
  double getAngle(double new_angle, double new_rate, double dt) {
    // Zaman güncelleme denklemleri (Zaman güncellemesi -> "Tahmin")
    // Adım 1
    rate = new_rate - bias; // Tahmini oran
    angle += dt * rate; // Tahmini açı

    // Tahmin hata kovaryansını güncelle
    // Adım 2
    P[0][0] = P[0][0] + (dt * (dt*P[1][1] - P[0][1] - P[1][0] + q_angle));
    P[0][1] = P[0][1] - (dt * P[1][1]);
    P[1][0] = P[1][0] - (dt * P[1][1]);
    P[1][1] = P[1][1] + (q_bias * dt);

    // Ölçüm ügncelleme denklemleri (Ölçüm güncellemesi -> "Düzeltme")
    // Kalman kazancını hesapla
    // Adım 3
    S = P[0][0] + r_measure;
    // Adım 4
    K[0] = P[0][0] / S;
    K[1] = P[1][0] / S;

    // Açıyı ve bias'ı hesapla. Tahmini ölçüm (newAngle) ile güncelle.
    // Adım 5
    y = new_angle - angle;

    // Adım 6
    angle += K[0] * y;
    bias += K[1] * y;

    // Ölçüm hata kovaryansını hesapla ve güncelle.
    // Adım 7
    P[0][0] -= K[0] * P[0][0];
    P[0][1] -= K[0] * P[0][1];
    P[1][0] -= K[1] * P[0][0];
    P[1][1] -= K[1] * P[0][1];

    // Hesaplanan açıyı döndür.
    return angle;
  };

  void setAngle(double new_angle) { angle = new_angle; }; // Açıyı değiştirir. Başlangıç açısını belirlemek için kullanılmalı.
  double getRate() { return rate; }; // Değişim oranını döndürür.

  // Kalman filtresini ayarlamak için kullanılan parametreler
  void setQangle(double new_q_angle) { q_angle = new_q_angle; };
  void setQbias(double new_q_bias) { q_bias = new_q_bias; };
  void setRmeasure(double new_r_measure) { r_measure = new_r_measure; };
  
  private:
  // Kalman filtresi parametreleri
  double q_angle; // İvmeölçer için gürültü değişimini işle.
  double q_bias; // Jiroskop biası için gürültü değişimini işle.
  double r_measure; // Ölçüm gürültüsü değişimi
  
  // Hesaplanan değerler
  double angle; // Kalman filtresi tarafından hesaplanan açı
  double bias; // Kalman filtresi tarafından hesaplanan jiroskop biası
  double rate; // Bias olmayan oran
  
  // Denklem değişkenleri
  double P[2][2]; // hata kovaryans matrisi
  double K[2]; // Kalman kazancı
  double y; // Açı farkı
  double S; // Tahmini hata
};

#endif
