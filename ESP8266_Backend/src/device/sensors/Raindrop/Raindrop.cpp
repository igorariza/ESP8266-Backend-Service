#include "Raindrop.h"
#include <Arduino.h>
#include "../include/config.h"

// lowest and highest sensor readings:
const int sensorMin = 0;    // sensor minimum
const int sensorMax = 1024; // sensor maximum

Raindrop::Raindrop()
{
}

Raindrop::~Raindrop()
{
}
void Raindrop::Raindrop_Init()
{
    // this->pin = pin;
    pinMode(USER_SETTINGS_WATERFLOW_DIGITAL_PIN, INPUT);
    delay(500);
}
float *Raindrop::Raindrop_Read()
{
    float *r = new float[3];
    int rainDigitalVal = digitalRead(USER_SETTINGS_WATERFLOW_DIGITAL_PIN);
    r[0] = rainDigitalVal;
    int rainAnalogVal = analogRead(USER_SETTINGS_WATERFLOW_PIN);
    r[1] = rainAnalogVal;
    r[2] = map(rainAnalogVal, sensorMin, sensorMax, 0, 3);
    
    return r;
}
int Raindrop::getRaindrop_count()
{
    Serial.println("Raindrop count: " + String(raindrop_count));
    return 0;
}
