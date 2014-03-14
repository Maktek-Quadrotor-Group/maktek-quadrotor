/*
 * Motor ve propeller test düzeneği kodudur.
 * Düzenekten elde edilecek hız ve itki değerleri alınacak seri iletişim kullanılarak 
 * bilgisayara iletilecek ve matlab kullanılarak quadcopter modeli için gerekli katsayılar 
 * hesaplanacaktır.
 */
 
// Debug modda çalıştırmak için uncomment edin  
#define DEBUG

// gerekli global değişkenler
float thrust = 0.0;
volatile float rpm = 0.0;

// gerekli pinler
const int thrustPin = A1;
const int rpmPin = 2;

// setup bölümü
void setup()
{
  //pin ayarları
  pinMode(2,INPUT);
  
  // seri iletişim başlatıldı.
  // boudrate 9600
  Serial.begin(9600); 
  
  // interrupt ayarı
  // 2. pine bağlanan mz80 ile yükselen kenarda oluşan interrupt kullanılarak rpm hesaplanıyor 
  attachInterrupt(0, calculateRpm, RISING);
}



// sonsuz döngü
void loop()
{
  // değerler hesaplanıyor
  calculateThrust();
  // değerler seri iletişim ile gönderiliyor
  writeToText();
  
  
  #ifdef DEBUG
    // Değerler seri monitöre yazdırılıyor
    Serial.print("RPM :");
    Serial.print("     ");
    Serial.print(rpm);
    
    Serial.print("THRUST :");
    Serial.print("     ");
    Serial.println(thrust);
  #endif
  
}
// motor sürme fonksiyonu
void driveMotor(){
}


// rpm hesaplama fonksiyonu
void calculateRpm(){
  float t,last_t=0.0,dt;
  t = micros();
  dt = t - last_t;
  rpm = (float)60.0/dt;
}


// thrust hesaplama fonksiyonu
void calculateThrust(){
}


void writeToText(){
  boolean counter = 0;
  unsigned int rpm_int = (int) rpm;
  unsigned int thrust_int = (int) thrust;
  
  if(counter == 0){
    Serial.write(rpm_int);
    counter++;
  }else{
    Serial.write(thrust_int);
    counter == 0;
  }
  
}
