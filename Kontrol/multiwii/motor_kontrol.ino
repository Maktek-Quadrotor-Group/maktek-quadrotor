/* Motor kontrol fonksiyonları
 *   ATmega32u4 datasheet: http://www.atmel.com/images/7766s.pdf
 */
#define MINCOMMAND  1000 // En düşük sinyal
#define NUMBER_MOTOR 4 // Motor sayısı

uint8_t PWM_PIN[4] = {9,10,5,6}; // PWM pinleri

// 'motor' dizisinin değerlerini PWM compare registerlarına yazar.
void writeMotors() { 
  // [1000;2000] => [125;250]
  // ATMega32U4'e özel PWM zamanlayıcıları ve registerlar

  // Timer 1 A & B [1000:2000] => [8000:16000]
  OCR1A = motor[0]<<3; // pin 9
  OCR1B = motor[1]<<3; // pin 10
  
  // Timer 4 A & D [1000:2000] => [1000:2000]
  OCR3A = motor[2]<<3; // pin 5      
  
  TC4H = motor[3]>>8; 
  OCR4D = (motor[3]&0xFF); // pin 6
}

// Tüm motorlara girilen değeri gönderir.
void writeAllMotors(int16_t mc) {
  for (uint8_t i = 0; i < NUMBER_MOTOR; i++) {
    motor[i]=mc;
  }
  writeMotors();
}

// PWM zamanlayıcıları ve registerları ayarlar.
void initOutput() {
  // Tüm PWM pinleri çıkış olarak ayarla.
  for(uint8_t i=0; i < NUMBER_MOTOR; i++) {
    pinMode(PWM_PIN[i],OUTPUT);
  }

  // ATMega32U4'e özel PWM zamanlayıcıları ve registerlar
  // Motor sayısı sıfırdan büyükse
  TCCR1A |= (1<<WGM11);                             // Faz düzeltme modu ve çarpan yok
  TCCR1A &= ~(1<<WGM10);
  TCCR1B &= ~(1<<WGM12) & ~(1<<CS11) & ~(1<<CS12);
  TCCR1B |= (1<<WGM13) | (1<<CS10);
  ICR1   |= 0x3FFF; // TOP to 16383;
  TCCR1A |= _BV(COM1A1); // 9. pini B kanalının 1. Timer'ına bağla.
    
  // Motor sayısı birten büyükse
  TCCR1A |= _BV(COM1B1); // 10. pini B kanalının 1. Timer'ına bağla.
  
  // Motor sayısı ikiden büyükse
  TCCR3A |= (1<<WGM31); // phase correct mode & no prescaler
  TCCR3A &= ~(1<<WGM30);
  TCCR3B &= ~(1<<WGM32) &  ~(1<<CS31) & ~(1<<CS32);
  TCCR3B |= (1<<WGM33) | (1<<CS30); 
  ICR3   |= 0x3FFF; // TOP to 16383;     
  TCCR3A |= _BV(COM3A1); // connect pin 5 to timer 3 channel A    
    
  // Motor sayısı üçten büyükse
  TCCR4E |= (1<<ENHC4); // enhanced pwm mode
  TCCR4B &= ~(1<<CS41); TCCR4B |= (1<<CS42)|(1<<CS40); // Çarpan 16
  TCCR4D |= (1<<WGM40); TC4H = 0x3; OCR4C = 0xFF; // phase and frequency correct mode & top to 1023 but with enhanced pwm mode we have 2047
  TCCR4C |= (1<<COM4D1)|(1<<PWM4D); // connect pin 6 to timer 4 channel D
  
  writeAllMotors(MINCOMMAND);
  delay(300);
}

void writeMotor1() {
    OCR1A = motor[0]<<3; // pin 9
}

void writeMotor2() {

  OCR1B = motor[1]<<3; // pin 10
}

void writeMotor3() {
  OCR3A = motor[2]<<3; // pin 5      
}

void writeMotor4() {
  TC4H = motor[3]>>8; 
  OCR4D = (motor[3]&0xFF); // pin 6
}
