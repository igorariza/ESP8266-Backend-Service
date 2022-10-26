#ifndef FC28_SOILMOISTURE_H_
#define FC28_SOILMOISTURE_H_
#include "Arduino.h"


class FC28_SoilMoisture
{
public:
    FC28_SoilMoisture();
    void FC28_SoilMoisture_Init();
    float FC28_SoilMoisture_Read();
};

#endif /* FC28_SOILMOISTURE_H_ */