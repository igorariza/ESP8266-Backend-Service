#include "WifiConnect.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>
// Your WiFi credentials
#define WIFI_SSID "Home_"
#define WIFI_PASSWORD "Home_1234"

void WifiConnect() {}

void WifiConnect::wifi_Init()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        Serial.print(WiFi.status());
        Serial.print("\n");
        Serial.print(WiFi.localIP());
        delay(500);
    }
    Serial.println(WiFi.localIP());
    Serial.println();
}

int WifiConnect::status_Wifi()
{
    if (WiFi.status() == 1)
    {
        Serial.println("WiFi is connected...");
        return WiFi.status();
    }
    else
    {
        Serial.println("WiFi is not connected...");
        delay(5000);
        return WiFi.status();
    }
    return WiFi.status();
}

void WifiConnect::wifi_reconnect()
{
    if (WiFi.status() != 1)
    {
        Serial.println("WiFi is not connected...");
    }
    else
    {
        Serial.println("WiFi is connected...");
    }
}
