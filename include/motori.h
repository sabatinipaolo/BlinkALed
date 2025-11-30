#ifndef MOTORI_H
#define MOTORI_H

#include <Arduino.h>

#define AD_PIN_A PA_2
#define AD_PIN_B PA_3

#define AS_PIN_A PA_0
#define AS_PIN_B PA_1

#define PD_PIN_A PB_7
#define PD_PIN_B PB_8

#define PS_PIN_A PA_6
#define PS_PIN_B PA_7


class Motore
{
public:
    Motore(int pinA, int pinB);
    void orario(int pwm);
    void antiorario(int pwm);
    void stop();
    void muovi(int pwm);

    void test_avanti_indietro(int pwm);

private:
    int _pinA;
    int _pinB;
};

Motore::Motore(int pinA, int pinB)
    : _pinA(pinA), _pinB(pinB)
{
    pinMode(_pinA, OUTPUT);
    pinMode(_pinB, OUTPUT);
};

void Motore::orario(int pwm)
{
    analogWrite(_pinA, pwm);
    analogWrite(_pinB, LOW);
}
void Motore::antiorario(int pwm)
{
    analogWrite(_pinA, LOW);
    analogWrite(_pinB, pwm);
}

void Motore::stop()
{
    analogWrite(_pinA, LOW);
    analogWrite(_pinB, LOW);
}

void Motore::muovi(int velocita)
{
    

    if (velocita > 0)
    {   int pwm = map(  velocita, 0,255, 0, 255);
        orario(pwm);
    }
    else if (velocita < 0)
    {   
        int pwm = map(  -velocita, 0,255, 0, 255);
        antiorario(-pwm);
    }
    else
    {
        stop();
    }
}

void Motore::test_avanti_indietro(int pwm){ 
    orario(pwm);
    delay (2000);
    stop();
    delay (1000);
    antiorario(pwm);
    delay (2000);
    stop();
    delay (1000);

}

#endif // MOTORI_H