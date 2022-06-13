#include <Arduino.h>
#include <ESP8266WiFi.h>

//#include <TimeLib.h>
#include "data/wifi/WifiConnect.h"
#include "data/firebase/Firebase.h"
#include "device/sensors/DHT11-temperature/DHT11_temperature.h"
#include "device/sensors/Yfs201-waterFlow/WaterFlow.h"
#include "device/actuactors/rele/Rele.h"

WifiConnect *wifi;
int status_wifi;
FirebaseConnect *firebase;
DHT11_temperature *dht11;
WaterFlow *waterFlow;
// Rele *rele;
// int LED_D1 = 5;  // d1 pertenece al 5
int DHTpin = D1; // D5 of NodeMCU ior 5 Arduino uno
// int RelePin = D2; // Rele 5v
float temperature;

const int led_pin = 14;
const int sensor_pin = 13;
const int sensor_pin_water = A0;

void setup()
{
  Serial.begin(9600);
  wifi->wifi_Init();

  //   // firebase->Firebase_Init();
  //   // Serial.println("Firebase_Init()");
  //   // delay(1000);
  //   // Serial.println("Starting...");
  //   // dht11->DHT11_Init(DHTpin);
  //   // delay(1000);
  //   // // rele->Rele_Init(RelePin);
  //   // delay(1000);
  //   // waterFlow->WaterFlow_Init(sensor_pin_water);
  //   // Serial.println("WaterFlow_Init()");
  //   // delay(1000);
}

void loop()
{
  Serial.println("Looping...");
  delay(1000);
  //   //status_wifi = wifi->status_Wifi();
  //   //Serial.println("status_wifi: " + String(status_wifi));
  //   // firebase->Firebase_Update();
  //   // Serial.println("firebase->Firebase_Update()");
  //   // delay(1000);
  //   // temperature = dht11->DHT11_Read();
  //   // Serial.print("Temperature: ");
  //   // Serial.print(temperature);
  //   // firebase->Firebase_Update_Temp(temperature);
  //   // delay(10000);
  //   // waterFlow->getFlow();
  //   // Serial.println("waterFlow->getFlow()");
  //   // delay(1000);
  //   // // rele->Switch_Status();
  //   // delay(1000);
}
