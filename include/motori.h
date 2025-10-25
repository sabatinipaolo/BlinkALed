#ifndef MOTORI_H
#define MOTORI_H

#include <Arduino.h>

class Motore
{
public:
    Motore(int pinA, int pinB);
    void orario(int pwm);
    void antiorario(int pwm);

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

#endif // MOTORI_H