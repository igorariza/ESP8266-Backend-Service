#include "WaterFlow.h"
#include "../include/config.h"

volatile int flow_frequency; // Measures flow meter pulses
unsigned int l_hour;         // Calculated litres/hour
unsigned long currentTime;
unsigned long cloopTime;

char push_data[200]; // string used to send info to the server ThingSpeak
int addr = 0;        // endereço eeprom

// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// litre/minute of flow.
float calibrationFactor = 4.5;

volatile byte pulseCount;

float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;

unsigned long oldTime;

// void ICACHE_RAM_ATTR flow() // Interrupt function
// {
//     flow_frequency++;
// }

void WaterFlow::WaterFlow_Init()
{

    pulseCount = 0;
    flowRate = 0.0;
    flowMilliLitres = 0;
    totalMilliLitres = 0;
    oldTime = 0;

    // digitalWrite(buttonPin, HIGH);

    pinMode(USER_SETTINGS_WATERFLOW_DIGITAL_PIN, INPUT);
    // attachInterrupt(digitalPinToInterrupt(USER_SETTINGS_WATERFLOW_DIGITAL_PIN), flow, RISING);

    sei(); // Enable interrupts
    currentTime = millis();
    cloopTime = currentTime;
    Serial.println("WaterFlow::WaterFlow_Init()");
}

float WaterFlow::WaterFlow_Read()
{
    // Disable the interrupt while calculating flow rate and sending the value to
    // the host
    detachInterrupt(USER_SETTINGS_WATERFLOW_DIGITAL_PIN);
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;

    oldTime = millis();
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;

    unsigned int frac;
    Serial.print("Flow rate: ");
    Serial.print(int(flowRate)); 
    Serial.print("."); 
    frac = (flowRate - int(flowRate)) * 10;
    Serial.print(frac, DEC); 
    Serial.print("L/min");
    // Print the number of litres flowed in this second
    Serial.print("  Current Liquid Flowing: "); // Output separator
    Serial.print(flowMilliLitres);
    Serial.print("mL/Sec");
    // Print the cumulative total of litres flowed since starting
    Serial.print("  Output Liquid Quantity: "); // Output separator
    Serial.print(totalMilliLitres);
    Serial.println("mL");

    if (flowRate > 0)
    {
        delay(100);
    }

    
    return flowRate;
}

float WaterFlow::getFlow()
{
    currentTime = millis();
    // Every second, calculate and print litres/hour
    if (currentTime >= (cloopTime + 1000))
    {
        cloopTime = currentTime; // Updates cloopTime
        // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min. (Results in +/- 3% range)
        l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour
        flow_frequency = 0;                   // Reset Counter
        Serial.print(l_hour, DEC);            // Print litres/hour
        Serial.println(" L/hour \n");
    }
    return l_hour;
}
