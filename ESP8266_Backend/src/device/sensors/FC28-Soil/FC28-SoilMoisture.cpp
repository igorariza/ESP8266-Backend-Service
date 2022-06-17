#include "FC28-SoilMoiusture.h"
#include "../include/config.h"

void FC28_SoilMoisture::FC28_SoilMoisture_Init()
{
    pinMode(MOISTURE_PIN, INPUT);
    Serial.println("FC28_SoilMoisture::FC28_SoilMoisture_Init()");
}

float FC28_SoilMoisture::FC28_SoilMoisture_Read()
{
    float moisture = analogRead(MOISTURE_PIN);
    Serial.print("FC28_SoilMoisture::FC28_SoilMoisture_Read() - moisture: ");
    return moisture;
}


