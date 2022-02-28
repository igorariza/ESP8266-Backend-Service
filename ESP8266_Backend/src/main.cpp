#include <Arduino.h>
#include "data/wifi/WifiConnect.h"
#include "data/firebase/Firebase.h"
#include "device/sensors/DHT11-temperature/DHT11_temperature.h"

WifiConnect *wifi;
FirebaseConnect *firebase;
DHT11_temperature *dht11;

int DHTpin = D5; // D5 of NodeMCU ior 5 Arduino uno
float temperature;

const int led_pin = 14;
const int sensor_pin = 13;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  wifi->wifi_Init();
  delay(1000);
  firebase->Firebase_Init();
  Serial.println("Firebase_Init()");
  delay(1000);
  Serial.println("Starting...");
  dht11->DHT11_Init(DHTpin);
  delay(1000);
}

void loop()
{

  // put your main code here, to run repeatedly:
  wifi->status_Wifi();
  delay(1000);
  // firebase->Firebase_Update();
  // Serial.println("firebase->Firebase_Update()");
  delay(1000);
  temperature = dht11->DHT11_Read();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  firebase->Firebase_Update_Temp(temperature);
  delay(10000);
}
