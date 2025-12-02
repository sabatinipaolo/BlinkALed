#ifndef ROBOT_H
#define ROBOT_H

#include "motori.h"
constexpr double radice2_su2 = 0.70710678118654752440084436210485;
constexpr double quarantacinque = 0.78539816339744830961566084581988;


class Robot {
public:
    Robot();
    void trasla_alla_massima_velocita(int alfa);
    void trasla(int alfa, int velocita);
    void stop();

    void muovi_nord_est(int velocita);
    void muovi_sud_ovest(int velocita);

    void muovi_sud_est(int velocita);

    void muovi_nord_ovest(int velocita);

    Motore  motori[4] ;
    Motore& _mot_ant_dx;
    Motore& _mot_ant_sx;
    Motore& _mot_pos_dx;
    Motore& _mot_pos_sx;
    
 
    void test_motori();
};



Robot::Robot()
    : motori{ Motore(AD_PIN_A, AD_PIN_B),
              Motore(PD_PIN_A, PD_PIN_B),
              Motore(PS_PIN_A, PS_PIN_B),
              Motore(AS_PIN_A, AS_PIN_B)
             
               },
      _mot_ant_dx(motori[0]),
      _mot_pos_dx(motori[1]),
      _mot_pos_sx(motori[2]),
      _mot_ant_sx(motori[3])
    
{
    stop();
}

void Robot::trasla_alla_massima_velocita(int alfa) 
{
    
}
void Robot::trasla(int alfa, int velocita) 
{

    double cosa = cos(alfa + quarantacinque);
    double sina = sin(alfa + quarantacinque);

    
    int vad = static_cast<int>(-velocita * radice2_su2*sina);
    int vps = -vad;
    
    int vas = static_cast<int>(velocita * radice2_su2*cosa );
    int vpd = -vas;
    
    _mot_ant_dx.muovi(vad);
    _mot_pos_dx.muovi(vpd);
    _mot_ant_sx.muovi(vas);
    _mot_pos_sx.muovi(vps);
}

void Robot::stop() 
{
    _mot_ant_dx.stop();
    _mot_pos_dx.stop();
    _mot_ant_sx.stop();
    _mot_pos_sx.stop();
}

void Robot::muovi_nord_est(int velocita)
{
    _mot_ant_dx.stop();
    _mot_pos_dx.muovi(velocita);
    _mot_ant_sx.muovi(-velocita);
    _mot_pos_sx.stop();
}

void Robot::muovi_sud_ovest(int velocita)
{
    muovi_nord_est(-velocita);
}

void Robot::muovi_sud_est(int velocita)
{
    _mot_ant_dx.muovi(-velocita);
    _mot_pos_dx.stop();
    _mot_ant_sx.stop();
    _mot_pos_sx.muovi(velocita);
}

void Robot::muovi_nord_ovest(int velocita)
{
    muovi_sud_est(-velocita);
}

void Robot::test_motori()
{
    for (int i = 0; i < 4; i++)
    {
        motori[i].test_avanti_indietro(200);
    }
}
#endif // ROBOT_H