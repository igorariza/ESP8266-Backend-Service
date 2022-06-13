#ifndef RAINDROP_H
#define RAINDROP_H
#include "Arduino.h"

class Raindrop
{
private:
    int pin;
    int raindrop_count;

public:
    Raindrop();
    ~Raindrop();
    void Raindrop_Init(int pin);
    int Raindrop_Read();
    int getRaindrop_count();
};

#endif