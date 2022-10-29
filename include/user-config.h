/* 1.0.0 VERSION */
#ifndef user_config_h
#define user_config_h
// Setup
#define HOUR_INIT 7
#define HOUR_END 23
#define MAX_TRANSPIRATION_TIME 12
#define MAX_ABSORPTION_TIME 18

// WIFI SETTINGS
#define USER_SETTINGS_WIFI_SSID "Home_"
#define USER_SETTINGS_WIFI_PASSWORD "Home_1234"
#define USER_SETTINGS_WIFI_HOSTNAME "X"
// FIREBASE SETTINGS
#define DEVICE_UID "1X"
// Your Firebase Project Web API Key
#define API_KEY "AIzaSyClBzhWYZIuelrs_7QLBunvXD26JzXoblo"
// Your Firebase Realtime database URL
#define DATABASE_URL "https://smartfarming-cde84-default-rtdb.firebaseio.com/"
// Insert Authorized Email and Corresponding Password
#define USER_EMAIL "ggroupar@gmail.com"
#define USER_PASSWORD "ia2127374"
#define USER_SETTINGS_FIREBASE_HOST ""
#define USER_SETTINGS_FIREBASE_AUTH ""
// SENSOR DHT11 SETTINGS
#define USER_SETTINGS_DHT11_PIN D1
// ACTUATOR RELE SETTINGS
#define USER_SETTINGS_RELE_PIN D2
// SENSOR WATERFLOW SETTINGS
#define USER_SETTINGS_WATERFLOW_ANALOG_PIN A0
#define USER_SETTINGS_WATERFLOW_DIGITAL_PIN D3

// SENSOR YFS201 SETTINGS
#define USER_SETTINGS_YFS201_PIN D4

// SENSOR RAINDROP SETTINGS
#define USER_SETTINGS_RAINDROP_PIN D5

// Rtcds3231 SETTINGS
#define RTC_SDA D6
#define RTC_SCL D5
#define RTC_INIT "07:00:00"

// Date Time

// FC28-SoilMoisture SETTINGS
#define MOISTURE_THRESHOLD 55 // moisture alert threshold
#define MOISTURE_PIN D0       // moisture sensor pin

#endif