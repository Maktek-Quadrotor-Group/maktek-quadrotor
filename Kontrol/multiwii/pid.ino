/* PID kontrolcüsü
 */
#ifndef pid_h_
#define pid_h_

// Pid sınıfı başlangıcı
class Pid {
  public:
  // Consructor: Gerekli değişkenlerin adreslerini alır.
  Pid(float* set_input, float* set_output, float* set_reference, float set_kp, float set_ki, float set_kd) {
    input = set_input; // Kontrol edilmek istenen değişken
    output = set_output; // Kontrol çıkışı
    reference = set_reference; // Ulaşılmak istenen referans noktası
    
    // Parametreleri ayarla
    dt = 200; // Döngü süresi
    dtInSec = dt / 1000; // Saniye cinsinden döngü süresi
    max_output = 255; // Kontrol çıkışının sınırı
    kp = set_kp / dt_in_sec; // P kazancı
    ki = set_ki * dt_in_sec; // I kazancı
    kd = set_kd; // D kazancı
    
    last_time = millis() - dt; // Bir sonraki döngü için zamanı ayarla.
  }
  
  // Bir sonraki PID kontrol çıkışını hesaplar.
  void compute() {
    unsigned long now; // Hesaplanan anın saklandığı değişken
    while((now = millis()) - last_time < dt) {} // Örnekleme zamanı tamamlanana kadar bekle.
    
    // Hatayı hesapla.
    float current_input = *input; // Kontrol edilen değişkenin o anki değerini sakla.
    float error = *reference - current_input; // Hatayı hesapla.
    
    // Kontrol çıkışını hesapla.
    p_term = kp * error; // P terimini hesapla
    i_term = constrain(i_term + (ki * error), 0, max_output); // I terimini hesapla. İzin verilen sınırlar içinde tut.
    d_term = kd * (last_input - current_input) // D terimini hesapla
    
    *output = constrain(p_term + i_term - d_term, 0, max_output); // Toplam çıktıyı hesapla ve kontrol çıkışını bu değere eşitle.
    
    // Bir sonraki döngü için saklanacak değerler
    last_input = current_input; // Bir önceki döngüde kontrol değişkeni
    last_time = now; // Bir önceki döngünün hesaplandığı zaman
  }
  
  // Kp, Ki ve Kd katsayılarını değiştirir.
  void setParams(float set_kp, float set_ki, float set_kd) {
    // Sıfırdan küçük bir değer girildiyse orjinal değeri koru.
    if (set_kp < 0) set_kp = kp;
    if (set_ki < 0) set_ki = ki;
    if (set_kd < 0) set_kd = kd;
    
    // Yeni değerleri ata.
    kp = set_kp;
    ki = set_ki * dt_in_sec;
    kd = set_kd / dt_in_sec;
  }
  
  private:
    // Pid parametreleri
    float kp; // P kazancı
    float ki; // I kazancı
    float kd; // D kazancı
    int dt; // Milisaniye biriminde örnekleme zamanı
    float dt_in_sec; // Saniye biriminde örnekleme zamanı
    
    // Kontrol değişkenleri
    float* input; // Kontrol değişkeni
    float* output; // Kontrol çıkışı
    float* reference; // Referans değişkeni
    float last_input; // Bir önceki değerin saklandığı değişken
    
    // Pid değişkenleri
    float max_output; // Kontrol çıkışının sınırı
    float p_term; // P terimi
    float i_term; // I terimi
    float d_term; // D terimi
    
    // Zaman değişkenleri
    unsigned long last_time;
};

#endif
