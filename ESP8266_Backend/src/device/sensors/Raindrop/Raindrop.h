#ifndef RAINDROP_H
#define RAINDROP_H
#include "Arduino.h"

class Raindrop
{
private:
    int pin;
    int raindrop_count = 0;

public:
    Raindrop();
    ~Raindrop();
    void Raindrop_Init();
    float *Raindrop_Read();
    int getRaindrop_count();
};

#endif