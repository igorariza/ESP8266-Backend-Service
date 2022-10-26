#ifndef WATERFLOW_H_
#define WATERFLOW_H_
#include "Arduino.h"

class WaterFlow
{
public:
    WaterFlow();
    void WaterFlow_Init();
    float WaterFlow_Read();
    float getFlow();
};
#endif /* WATERFLOW_H_ */