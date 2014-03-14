#include <avr/io.h>
#include <avr/pgmspace.h>

#define __AVR_ATmega32U4__

static int16_t motor[4];

void setup()
{
  initOutput();
}

void loop()
{
  writeAllMotors(1500);
  delay(3000);

  writeAllMotors(2047);
  delay(3000);
  
}
