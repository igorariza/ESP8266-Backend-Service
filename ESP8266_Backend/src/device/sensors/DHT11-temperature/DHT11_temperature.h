#ifndef DHT11_H
#define DHT11_H
#include "Arduino.h"
#include "DHTesp.h"

class DHT11_temperature
{
public:
    DHT11_temperature();
    void DHT11_Init();
    float DHT11_Read();
    float getTemperature();
    float getHumidity();
};

#endif