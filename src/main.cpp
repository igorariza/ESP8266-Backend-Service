#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <SimpleTimer.h>

#include "data/RtcDs/RtcDs.h"
#include "data/wifi/WifiConnect.h"
#include "data/firebase/Firebase.h"
#include "device/sensors/DHT11-temperature/DHT11_temperature.h"
#include "device/sensors/Yfs201-waterFlow/WaterFlow.h"
#include "device/actuactors/rele/Rele.h"
#include "device/sensors/Raindrop/Raindrop.h"
#include "device/sensors/FC28-Soil/FC28-SoilMoiusture.h"
#include "../include/config.h"

RtcDs *rtcds;
WifiConnect *wifi;
FirebaseConnect *firebase;
DHT11_temperature *dht11;
WaterFlow *waterFlow;
Rele *rele;
Raindrop *raindrop;
FC28_SoilMoisture *fc28_soilMoisture;
SimpleTimer timer;

String rtcstatus;
String rtsdate;
String rtcTemperature;
bool initday = false;
int timeReview = 10000;
int status_wifi;
float temperature = 25.0;
long lastMsg = 0;

// void setup_wifi()
// {
//   delay(10);

//   Serial.println("Connecting to");
//   Serial.println(USER_SETTINGS_WIFI_SSID);

//   WiFi.begin(USER_SETTINGS_WIFI_SSID, USER_SETTINGS_WIFI_PASSWORD);

//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print("connecting to WiFi.. \n");
//   }

//   Serial.println("Wifi connected");
//   Serial.println("IP-address: ");
//   Serial.println(WiFi.localIP());
// }

void rainData()
{
  Serial.println("Rain data");
}

void dayInit()
{
  Serial.println("Init day");
  temperature = temperature + 1;
  firebase->Firebase_Update_Temp(temperature);
  initday = true;
}

void monitor()
{
  Serial.println("Monitor");
  temperature = temperature + 1;
  firebase->Firebase_Update_Temp(temperature);
  Serial.println("zzzz");
  ESP.deepSleep(6e+7);

  ESP.
  Serial.println("ready");
  delay(2000);
  // float *r = raindrop->Raindrop_Read();
  // if (r[0] == 0)
  // {
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
  //   Serial.println("it's not raining : ");
  //   Serial.println(r[0]);
  //   Serial.println("\n");
  //   Serial.println(r[1]);
  //   Serial.println("\n");
  //   Serial.println(r[2]);
  // }
  // else
  // {
  //   Serial.println("Error");
  // }
  // delay(2000);
  // float soilMoisture = fc28_soilMoisture->FC28_SoilMoisture_Read();
  // Serial.println("Soil Moisture: " + String(soilMoisture));
  // delay(2000);
  // float waterFlow = waterFlow->WaterFlow_Read();
  // Serial.println("Water Flow: " + String(waterFlow));
  // delay(2000);
  // rele->Rele_Read();
  // delay(2000);
}

void validateTime(String rtcTime)
{
  int hour = rtcTime.substring(0, 2).toInt();
  int minute = rtcTime.substring(3, 5).toInt();
  int second = rtcTime.substring(6, 8).toInt();
  Serial.println("Hour: " + String(hour));
  Serial.println("Minute: " + String(minute));
  Serial.println("Second: " + String(second));
  delay(2000);
  switch (hour)
  {
  case HOUR_INIT:
    Serial.println("Hour Init");
    initday = true;
    ESP.deepSleep(3.6e+9);
    break;
  case HOUR_END:
    Serial.println("Hour End");
    initday = false;
    ESP.deepSleep(3.6e+9);
    break;
  case MAX_TRANSPIRATION_TIME:
    Serial.println("Max Transpiration Time");
    ESP.deepSleep(3.6e+9);
    break;
  case MAX_ABSORPTION_TIME:
    Serial.println("Max Absorption Time");
    ESP.deepSleep(3.6e+9);
    break;
  default:
    Serial.println("Mode Normal");
    monitor();
    break;
  }
}

void setup()
{
  Serial.begin(9600);
  timer.setInterval(1000, rainData);
  Serial.println("Starting Rtcds timer");
  rtcds->RtcInit();
  wifi->wifi_Init();
  firebase->Firebase_Init();
  Serial.println("Firebase_Init()");
  // dht11->DHT11_Init();
  // Serial.println("Starting DHT11 Temperature...");
  // Serial.println("Starting WaterFlow...");
  // waterFlow->WaterFlow_Init();
  // delay(500);
  // Serial.println("Starting Rele...");
  // rele->Rele_Init();
  // delay(500);
  // Serial.println("Starting Raindrop...");
  // raindrop->Raindrop_Init();
  // delay(500);
  // Serial.println("Starting SoilMoisture...");
  // fc28_soilMoisture->FC28_SoilMoisture_Init();
  delay(2000);
}

void loop()
{
  timer.run();

  if (initday == false)
  {
    Serial.println("Init day");
    delay(1000);
    dayInit();
  }
  else
  {
    Serial.println("Day already init");
    rtcstatus = rtcds->getRtcTime();
    delay(1000);
    validateTime(rtcstatus);
  }

  // delay(4000);
  // rtsdate = rtcds->RtcRead();
  // Serial.println("Rtc date: " + rtsdate);
  // delay(4000);
  // rtcTemperature = rtcds->getTemperature();
  // Serial.println("Rtc temperature: " + rtcTemperature);
  // delay(4000);
  // long now = millis();
  // delay(500);
  // Serial.println("Looping...");

  // if (now - lastMsg > timeReview)
  // {
  //   temperature = dht11->DHT11_Read();
  //   Serial.print("Temperature: ");
  //   Serial.print(temperature);
  //   delay(500);
  //   float *r = raindrop->Raindrop_Read();
  //   lastMsg = now;
  //   if (r[0] == 0)
  //   {
  //     Serial.println("it's raining : ");
  //     Serial.println(r[0]);
  //     Serial.println("\n");
  //     Serial.println(r[1]);
  //     Serial.println("\n");
  //     Serial.println(r[2]);
  //     delay(20000);
  //   }
  //   else if (r[0] == 1)
  //   {
  //     Serial.println("it's not raining : ");
  //     Serial.println(r[0]);
  //     Serial.println("\n");
  //     Serial.println(r[1]);
  //     Serial.println("\n");
  //     Serial.println(r[2]);
  //   }
  //   else
  //   {
  //     Serial.println("Error");
  //   }
  //   delay(2000);
  //   //setup_wifi();
  // }
}