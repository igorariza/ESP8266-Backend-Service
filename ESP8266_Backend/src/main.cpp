#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <SimpleTimer.h>

#include "data/wifi/WifiConnect.h"
// #include "data/firebase/Firebase.h"
#include "device/sensors/DHT11-temperature/DHT11_temperature.h"
#include "device/sensors/Yfs201-waterFlow/WaterFlow.h"
#include "device/actuactors/rele/Rele.h"
#include "device/sensors/Raindrop/Raindrop.h"
#include "device/sensors/FC28-Soil/FC28-SoilMoiusture.h"
#include "../include/config.h"

WifiConnect *wifi;
// FirebaseConnect *firebase;
DHT11_temperature *dht11;
WaterFlow *waterFlow;
Rele *rele;
Raindrop *raindrop;
FC28_SoilMoisture *fc28_soilMoisture;
SimpleTimer timer;

int timeReview = 5000;

int status_wifi;
float temperature;
long lastMsg = 0;

void setup_wifi()
{
  delay(10);

  Serial.println("Connecting to");
  Serial.println(USER_SETTINGS_WIFI_SSID);
  WiFi.begin(USER_SETTINGS_WIFI_SSID, USER_SETTINGS_WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("connecting to WiFi.." + String(USER_SETTINGS_WIFI_SSID) + "\n");
    Serial.print("connecting to WiFi.." + String(USER_SETTINGS_WIFI_PASSWORD) + "\n");
    Serial.print("status: " + String(WiFi.status()) + "\n");
  }

  Serial.println("Wifi connected");
  Serial.println("IP-address: ");
  Serial.println(WiFi.localIP());
}

void rainData()
{
  Serial.println("Rain data");
}

void setup()
{
  Serial.begin(9600);
  // timer.setInterval(timeReview, rainData);
  wifi->wifi_Init();
  // firebase->Firebase_Init();
  // Serial.println("Firebase_Init()");
  delay(500);
  // Serial.println("Starting DHT11 Temperature...");
  // dht11->DHT11_Init();
  delay(500);
  // Serial.println("Starting WaterFlow...");
  // Serial.println("Starting Raindrop...");
  // raindrop->Raindrop_Init();
  delay(500);
  // waterFlow->WaterFlow_Init();
  delay(500);
  // Serial.println("Starting Rele...");
  // rele->Rele_Init();
  delay(500);
  // rele->Switch_On();
  delay(500);

  // Serial.println("Starting SoilMoisture...");
  // fc28_soilMoisture->FC28_SoilMoisture_Init();
  // delay(2000);
}

void loop()
{
  // timer.run();
  // wifi->status_Wifi();
  // long now = millis();
  Serial.println("Looping...");
  // rele->Switch_Off();
  // rele->Switch_On();
  delay(10000);
  // temperature = dht11->DHT11_Read();
  // Serial.println("\n");
  // Serial.print("Temperature: ");
  // Serial.print(temperature);
  delay(500);
  // float *r = raindrop->Raindrop_Read();
  // // lastMsg = now;
  // if (r[0] == 0)
  // {
  //   Serial.println("\n");
  //   Serial.println("it's raining : ");
  //   Serial.println(r[0]);
  //   Serial.println("\n");
  //   Serial.println(r[1]);
  //   Serial.println("\n");
  //   Serial.println(r[2]);
  //   delay(20000);
  // }
  // else if (r[0] == 1)
  // {
  //   Serial.println("\n");
  //   Serial.println("it's not raining : ");
  //   Serial.println(r[0]);
  //   Serial.println("\n");
  //   Serial.println(r[1]);
  //   Serial.println("\n");
  //   Serial.println(r[2]);
  // }
  // waterFlow->WaterFlow_Read();
  delay(500);
  // waterFlow->getFlow();
  delay(500);

  // rele->Switch_On();
  //  if (now - lastMsg > timeReview)
  //  {

  //   Serial.println("Rele::Switch_On()");
  //   delay(2000);
  //   lastMsg = now;
  // }else{
  //   rele->Switch_Off();
  //   Serial.println("Rele::Switch_Off()");
  //   delay(2000);
  // }

  // if (now - lastMsg > timeReview)
  // {
  //   temperature = dht11->DHT11_Read();
  //   Serial.print("Temperature: ");
  //   Serial.print(temperature);
  //   delay(500);

  //   else
  //   {
  //     Serial.println("Error");
  //   }

  //   delay(2000);
  setup_wifi();
  // }
}
