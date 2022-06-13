#include "Raindrop.h"
#include <Arduino.h>

// lowest and highest sensor readings:
const int sensorMin = 0;    // sensor minimum
const int sensorMax = 1024; // sensor maximum

Raindrop::Raindrop()
{
}

Raindrop::~Raindrop()
{
}
void Raindrop::Raindrop_Init(int pin)
{
    this->pin = pin;
    this->raindrop_count = 0;
    delay(500);
    pinMode(pin, INPUT);
}
int Raindrop::Raindrop_Read()
{
    // read the sensor on analog A0:
    int sensorReading = analogRead(this->pin);
    // map the sensor range (four options):
    // ex: 'long int map(long int, long int, long int, long int, long int)'
    int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
    // range value:
    switch (range)
    {
    case 0:
        this->raindrop_count = 0;
        Serial.println("Rain warning");
        break;
    case 1:
        this->raindrop_count = 1;
        Serial.println("Not raining");
    }
    return this->raindrop_count;
}
int Raindrop::getRaindrop_count()
{
    Serial.println("Raindrop count: " + String(raindrop_count));
    return raindrop_count;
}
