#include "WifiConnect.h"
#include <ESP8266WiFi.h>
#include <SD.h>
#include <WiFi.h>
// Your WiFi credentials
#define WIFI_SSID "Home_"
#define WIFI_PASSWORD "Home_1234"

void WifiConnect() {}

void WifiConnect::wifi_Init()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
}

void WifiConnect::status_Wifi()
{
    Serial.print("WiFi status: ");
    Serial.println(WiFi.SSID());
}
