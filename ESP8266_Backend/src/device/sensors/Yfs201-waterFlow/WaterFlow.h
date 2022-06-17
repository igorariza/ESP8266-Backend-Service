#ifndef WATERFLOW_H
#define WATERFLOW_H
#include "Arduino.h"

class WaterFlow
{
public:
    WaterFlow();
    void WaterFlow_Init();
    float WaterFlow_Read();
    float getFlow();
};
#endif