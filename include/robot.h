#ifndef ROBOT_H
#define ROBOT_H

#include "motori.h"
constexpr double radice2_su2 = 0.70710678118654752440084436210485;
constexpr double quarantacinque = 0.78539816339744830961566084581988;


class Robot {
public:
    Robot();
    void trasla(int alfa, int velocita); 
    void stop() ;
    void test_MAD();    
    void test_MAS();
    void test_PAD();
    void test_PAS();
    
    
    


    Motore _mot_ant_dx;
    Motore _mot_ant_sx;
    Motore _mot_post_dx;
    Motore _mot_post_sx;
    
    private:
    void test_motore(Motore & motore);
};


Robot::Robot() 
    :   _mot_ant_dx(AD_PIN_A, AD_PIN_B),
        _mot_ant_sx(AS_PIN_A, AS_PIN_B),
        _mot_post_dx(PD_PIN_A, PD_PIN_B),
        _mot_post_sx(PS_PIN_A, PS_PIN_B)
{
    stop();
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
    _mot_post_dx.muovi(vpd);
    _mot_ant_sx.muovi(vas);
    _mot_post_sx.muovi(vps);
}

void Robot::stop() 
{
    _mot_ant_dx.stop();
    _mot_post_dx.stop();
    _mot_ant_sx.stop();
    _mot_post_sx.stop();
}

void Robot::test_MAD() 
{
    test_motore( _mot_ant_dx);
}

void Robot::test_MAS() 
{
    test_motore( _mot_ant_sx);
}
void Robot::test_PAS() 
{
    test_motore( _mot_post_sx);
}

void Robot::test_PAD() 
{
    test_motore( _mot_post_dx);
}


void Robot::test_motore( Motore &motore){
    motore.muovi(100);
    // delay(2000);
    // motore.stop();
    // delay(500);
    // motore.muovi(-100);
    // delay(2000);
    // motore.stop();
    // delay(5500);

}
#endif // ROBOT_H