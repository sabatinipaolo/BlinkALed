#include <Arduino.h>
#include "motori.h"

#define AD_PIN_A PA_0
#define AD_PIN_B PA_1

#define AS_PIN_A PA_2
#define AS_PIN_B PA_3

#define PD_PIN_A PB_7
#define PD_PIN_B PB_8

#define PS_PIN_A PA_6
#define PS_PIN_B PA_7

Motore motoreAD(AD_PIN_A, AD_PIN_B);
Motore motoreAS(AS_PIN_A, AS_PIN_B);

Motore motorePD(PD_PIN_A, PD_PIN_B);
Motore motorePS(PS_PIN_A, PS_PIN_B);

void setup()
{

  motorePD.orario(170);
  motorePS.orario(170);

  motoreAD.orario(170);
  motoreAS.orario(170);
}

void loop()
{
}