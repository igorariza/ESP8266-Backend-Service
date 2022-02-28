#include "WaterFlow.h"

void WaterFlow::WaterFlow_Init(int pin)
{
    pinMode(pin, INPUT);
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
