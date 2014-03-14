#define SW_PWM_P3  A1        
#define SW_PWM_P4  A0
uint8_t PWM_PIN[8] = {9,10,5,6,11,13,SW_PWM_P3,SW_PWM_P4};   //for a quad+: rear,right,left,front

#define MINTHROTTLE 1150
#define MAXTHROTTLE 1850
#define MINCOMMAND  1000
#define NUMBER_MOTOR 4


/**************************************************************************************/
/************  Writes the Motors values to the PWM compare register  ******************/
/**************************************************************************************/
void writeMotors() 
{ // [1000;2000] => [125;250]
/******** Specific PWM Timers & Registers for the atmega32u4 (Promicro)   ************/

  // Timer 1 A & B [1000:2000] => [8000:16000]
  OCR1A = motor[0]<<3; //  pin 9     
  
  OCR1B = motor[1]<<3; //  pin 10
  
  // Timer 4 A & D [1000:2000] => [1000:2000]
  OCR3A = motor[2]<<3; //  pin 5      
  
  TC4H = motor[3]>>8; OCR4D = (motor[3]&0xFF); //  pin 6
 
}

/**************************************************************************************/
/************          Writes the mincommand to all Motors           ******************/
/**************************************************************************************/
void writeAllMotors(int16_t mc) 
{   // Sends commands to all motors
  for (uint8_t i =0;i<NUMBER_MOTOR;i++) 
  {
    motor[i]=mc;
  }
  writeMotors();
}

/**************************************************************************************/
/************        Initialize the PWM Timers and Registers         ******************/
/**************************************************************************************/
void initOutput() 
{ /******* mark all PWM pins as Output *****************/
  for(uint8_t i=0;i<NUMBER_MOTOR;i++) 
  {
    pinMode(PWM_PIN[i],OUTPUT);
  }

/******** Specific PWM Timers & Registers for the atmega32u4 (Promicro)   ************/
 //if NUMBER_MOTOR > 0
      TCCR1A |= (1<<WGM11); // phase correct mode & no prescaler
      TCCR1A &= ~(1<<WGM10);
      TCCR1B &= ~(1<<WGM12) &  ~(1<<CS11) & ~(1<<CS12);
      TCCR1B |= (1<<WGM13) | (1<<CS10); 
      ICR1   |= 0x3FFF; // TOP to 16383;     
      TCCR1A |= _BV(COM1A1); // connect pin 9 to timer 1 channel A
    
    
    //if NUMBER_MOTOR > 1
      TCCR1A |= _BV(COM1B1); // connect pin 10 to timer 1 channel B
   
    
    //if NUMBER_MOTOR > 2
      // timer 3A
        TCCR3A |= (1<<WGM31); // phase correct mode & no prescaler
        TCCR3A &= ~(1<<WGM30);
        TCCR3B &= ~(1<<WGM32) &  ~(1<<CS31) & ~(1<<CS32);
        TCCR3B |= (1<<WGM33) | (1<<CS30); 
        ICR3   |= 0x3FFF; // TOP to 16383;     
        TCCR3A |= _BV(COM3A1); // connect pin 5 to timer 3 channel A    
    
    //if NUMBER_MOTOR > 3
        TCCR4E |= (1<<ENHC4); // enhanced pwm mode
        TCCR4B &= ~(1<<CS41); TCCR4B |= (1<<CS42)|(1<<CS40); // prescaler to 16
        TCCR4D |= (1<<WGM40); TC4H = 0x3; OCR4C = 0xFF; // phase and frequency correct mode & top to 1023 but with enhanced pwm mode we have 2047
        TCCR4C |= (1<<COM4D1)|(1<<PWM4D); // connect pin 6 to timer 4 channel D
  
  writeAllMotors(MINCOMMAND);
  delay(300);
  
}
