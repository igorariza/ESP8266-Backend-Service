#ifndef DHT11_H_
#define DHT11_H_
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

#endif /* DHT11_H_ */