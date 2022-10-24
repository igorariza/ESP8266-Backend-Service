#ifndef RAINDROP_H_
#define RAINDROP_H_
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

#endif /* RAINDROP_H_ */