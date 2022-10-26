#include "WaterFlow.h"
#include "../include/config.h"

void WaterFlow::WaterFlow_Init()
{
    pinMode(USER_SETTINGS_WATERFLOW_ANALOG_PIN, INPUT);
    Serial.println("WaterFlow::WaterFlow_Init()");
}

float WaterFlow::WaterFlow_Read()
{
    float flow = 0;
    flow = analogRead(A0);
    Serial.print("WaterFlow: ");
    Serial.print(flow);
    Serial.println(" ml/min");
    return flow;
}

float WaterFlow::getFlow()
{
    float flow = 0;
    flow = analogRead(A0);
    Serial.print("WaterFlow: ");
    Serial.print(flow);
    Serial.println(" ml/min");
    return flow;
}
