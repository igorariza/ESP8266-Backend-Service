#ifndef RELE_H_
#define RELE_H_
#include "Arduino.h"
using namespace std;

class Rele
{
public:
    Rele();
    int Get_Pin();
    void Set_Pin();
    bool Get_Status();
    void Set_Status(bool status);
    void Rele_Init();
    void Switch_On();
    void Switch_Off();
    void Switch_Toggle();
    void Switch_Status();

private:
    int pin;
    bool status;
};

#endif /* RELE_H_ */