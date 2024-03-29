#include "DHT11_temperature.h"
#include <DHTesp.h>

#include "../include/config.h"

DHTesp dht;


void DHT11_temperature::DHT11_Init()
{

    dht.setup(USER_SETTINGS_DHT11_PIN, DHTesp::DHT11);
    Serial.println("dht.getStatus()");
    Serial.println(dht.getStatus());
    delay(dht.getMinimumSamplingPeriod());
    Serial.println("DHT11_temperature::DHT11_Init()");
    // Initialize DHT11 sensor
}
// Read DHT11 sensor
float DHT11_temperature::DHT11_Read()
{
    float data[] = {0, 0};
    int j = 0;
    data[j] = dht.getTemperature();
    j++;
    data[j] = dht.getHumidity();
    Serial.print("Temperature: ");
    Serial.print(data[0]);
    Serial.print(" *C, Humidity: ");
    Serial.print(data[1]);
    Serial.println("%");
    return data[0];
}

float DHT11_temperature::getTemperature()
{

    float temperature = dht.getTemperature();
    return temperature;
}

float DHT11_temperature::getHumidity()
{
    float humidity = dht.getHumidity();
    return humidity;
}