
#include <avr/io.h>

#define DDRE _SFR_IO8(0x0D)
#define DDE2 2
#define DDE6 6

#define PORTE _SFR_IO8(0x0E)
#define PORTE2 2
#define PORTE6 6

#define EIMSK _SFR_IO8(0x1D)
#define INT0 0
#define INT1 1
#define INT2 2
#define INT3 3
#define INT4 4
#define INT5 5
#define INT6 6
#define INT7 7
#define EICRB _SFR_MEM8(0x6A)
#define ISC40 0
#define ISC41 1
#define ISC50 2
#define ISC51 3
#define ISC60 4
#define ISC61 5
#define ISC70 6
#define ISC71 7
#define PINE _SFR_IO8(0x0C)
#define PINE2 2
#define PINE6 6
#define ROLL       0
#define PITCH      1
#define YAW        2
#define THROTTLE   3

#define THROTTLEPIN  3
#define ROLLPIN      4
#define PITCHPIN     5
#define YAWPIN       2
#define AUX1PIN      6

#define PCINT_PIN_COUNT          4
#define PCINT_RX_BITS            (1<<1),(1<<2),(1<<3),(1<<4)

#define PCINT_RX_PORT                PORTB
#define PCINT_RX_MASK                PCMSK0
#define PCIR_PORT_BIT                (1<<0)
#define RX_PC_INTERRUPT              PCINT0_vect
#define RX_PCINT_PIN_PORT            PINB

#include <avr/pgmspace.h>




    
char* isimler[] = {"ROLL","PITCH","YAW","THROTTLE"};
static int16_t rcData[8];          // interval [1000;2000]

void setup(){
  configureReceiver();
  Serial.begin(9600);
}//end of setup

void loop(){
  computeRC();
  
  for(int i = 0; i < 4; i++){
    Serial.print(isimler[i]);
    Serial.print("\t");
    Serial.println(rcData[i]);
  }//end of for
  
  delay(200);

}//end of loop
