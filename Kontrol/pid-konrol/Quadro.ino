#include <Wire.h>

float kalman_angle_x;
float kalman_angle_y;
float output[2];

int dt = 200;
uint16_t last_t = 0;

void setup()
{
    Serial.begin(9600);
    Wire.begin(9600);
}
  
void loop()
{
  aciBul();

  Serial.print("kalman_angle_x : ");
  Serial.println(kalman_angle_x);
  
//  Serial.println(output[0]);
//  Serial.print(tkalman_angle_y :");
//  Serial.print(kalman_angle_y);
  
  Serial.println("");
  
  while (millis() - last_t < dt){};
  last_t = millis();
}
