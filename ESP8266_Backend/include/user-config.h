/* 1.0.0 VERSION */
#ifndef user_config_h
#define user_config_h
// WIFI SETTINGS
#define USER_SETTINGS_WIFI_SSID "Home_"
#define USER_SETTINGS_WIFI_PASSWORD "Home_1234"
#define USER_SETTINGS_WIFI_HOSTNAME "X"
// FIREBASE SETTINGS
#define USER_SETTINGS_FIREBASE_HOST ""
#define USER_SETTINGS_FIREBASE_AUTH ""
// SENSOR DHT11 SETTINGS
#define USER_SETTINGS_DHT11_PIN D1
// ACTUATOR RELE SETTINGS
#define USER_SETTINGS_RELE_PIN D3
// SENSOR WATERFLOW SETTINGS
#define USER_SETTINGS_WATERFLOW_ANALOG_PIN A0
#define USER_SETTINGS_WATERFLOW_DIGITAL_PIN D4
// SENSOR YFS201 SETTINGS
#define USER_SETTINGS_YFS201_PIN D2
// SENSOR RAINDROP SETTINGS
#define USER_SETTINGS_RAINDROP_PIN D5

//FC28-SoilMoisture SETTINGS
#define  MOISTURE_THRESHOLD     55   // moisture alert threshold
#define MOISTURE_PIN            D0   // moisture sensor pin

#endif