#include <Arduino.h>
#include <ESP8266WiFi.h>

//#include <TimeLib.h>
#include "data/wifi/WifiConnect.h"
#include "data/firebase/Firebase.h"
#include "device/sensors/DHT11-temperature/DHT11_temperature.h"
#include "device/sensors/Yfs201-waterFlow/WaterFlow.h"
#include "device/actuactors/rele/Rele.h"
#include "device/sensors/Raindrop/Raindrop.h"

// Your WiFi credentials
#define WIFI_SSID "Home_1"
#define WIFI_PASSWORD "Home1234"

WifiConnect *wifi;
int status_wifi;
FirebaseConnect *firebase;
DHT11_temperature *dht11;
WaterFlow *waterFlow;
Rele *rele;
Raindrop *raindrop;

// int LED_D1 = 5;  // d1 pertenece al 5
int DHTpin = D1;  // D5 of NodeMCU ior 5 Arduino uno
int RelePin = D2; // Rele 5v

float temperature;
long lastMsg = 0;
const int led_pin = 14;
const int sensor_pin = 13;
// const int sensor_pin_water = A0;

void setup_wifi()
{
  delay(10);

  // Serielle Ausgabe um Verbindungsaufbau darzustellen
  Serial.println("Connecting to");
  Serial.println(WIFI_SSID);

  // WiFi Verbindung aufbauen
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Verbindungsaufbau signalisieren
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("connecting to WiFi.. \n");
  }

  // Verbindung hergestellt
  Serial.println("Wifi connected");
  Serial.println("IP-address: ");
  Serial.println(WiFi.localIP());
}

void setup()
{
  Serial.begin(9600);

  // wifi->wifi_Init();
  // firebase->Firebase_Init();
  // Serial.println("Firebase_Init()");
  delay(500);
  Serial.println("Starting DHT11 Temperature...");
  dht11->DHT11_Init(DHTpin);
  delay(500);
  // delay(500);
  // Serial.println("Starting WaterFlow...");
  // waterFlow->WaterFlow_Init(sensor_pin_water);
  // delay(500);
  // Serial.println("Starting Rele...");
  // rele->Rele_Init(RelePin);
  // delay(500);
  Serial.println("starting Raindrop...");
  raindrop->Raindrop_Init();
  delay(500);
  //   // // rele->Rele_Init(RelePin);
  //   // delay(1000);
  //   // waterFlow->WaterFlow_Init(sensor_pin_water);
  //   // Serial.println("WaterFlow_Init()");
  //   // delay(1000);
}

void loop()
{
  Serial.println("Looping...");
  long now = millis();
  if (now - lastMsg > 10000)
  {
    temperature = dht11->DHT11_Read();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    delay(2000);
    float *r = raindrop->Raindrop_Read();
    lastMsg = now;
    if(r[0] == 0){
    Serial.println("it's raining : ");
    Serial.println(r[0]);
    Serial.println("\n");
    Serial.println(r[1]);
    Serial.println("\n");
    Serial.println(r[2]);
    delay(20000);
    }else if (r[0] == 1){
    {
      Serial.println("it's not raining : ");
      Serial.println(r[0]);
      Serial.println("\n");
      Serial.println(r[1]);
      Serial.println("\n");
      Serial.println(r[2]);
    }
    

    // // setup_wifi();
  }
  // Serial.println("now - lastMsg.....");
  // Serial.println(now - lastMsg);
  //   //status_wifi = wifi->status_Wifi();
  //   //Serial.println("status_wifi: " + String(status_wifi));
  //   // firebase->Firebase_Update();
  //   // Serial.println("firebase->Firebase_Update()");
  //   // delay(1000);

  // delay(500);

  // firebase->Firebase_Update_Temp(temperature);
  // delay(10000);
  // waterFlow->getFlow();
  // Serial.println("waterFlow->getFlow()");
  // delay(1000);
  // rele->Switch_Status();
  // delay(5000);
  // raindrop->Raindrop_Read();
}
