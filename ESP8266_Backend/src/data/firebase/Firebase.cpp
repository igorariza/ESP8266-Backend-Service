#include "Firebase.h"
#include <ESP8266WiFi.h>
#include <SD.h>
#include <WiFi.h>
#include <FirebaseESP8266.h>
// Provide the token generation process info.
#include "addons/TokenHelper.h"
// Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
#include <data/wifi/WifiConnect.h>
#define DEVICE_UID "1X"

// Your Firebase Project Web API Key
#define API_KEY "AIzaSyClBzhWYZIuelrs_7QLBunvXD26JzXoblo"
// Your Firebase Realtime database URL
#define DATABASE_URL "https://smartfarming-cde84-default-rtdb.firebaseio.com"

// Firebase Realtime Database Object
FirebaseData fbdo;
// Firebase Authentication Object
FirebaseAuth auth;
// Firebase configuration Object
FirebaseConfig config;

// Device Location config
String device_location = "Temperature";
// Firebase database path
String databasePath = "";
// Firebase Unique Identifier
String fuid = "";
// Stores the elapsed time from device start up
unsigned long elapsedMillis = 0;
// The frequency of sensor updates to firebase, set to 10seconds
unsigned long update_interval = 10000;
// Dummy counter to test initial firebase updates
int count = 0;
// Store device authentication status
bool isAuthenticated = false;

void FirebaseConnect() {}

void FirebaseConnect::Firebase_Init()
{
    // configure firebase API Key
    config.api_key = API_KEY;
    // configure firebase realtime database url
    config.database_url = DATABASE_URL;
    // Enable WiFi reconnection
    Firebase.reconnectWiFi(true);
    Serial.println("------------------------------------");
    Serial.println("Sign up new user...");
    // Sign in to firebase Anonymously
    if (Firebase.signUp(&config, &auth, "", ""))
    {
        Serial.println("Success");
        isAuthenticated = true;
        // Set the database path where updates will be loaded for this device
        databasePath = "/" + device_location;
        fuid = auth.token.uid.c_str();
    }
    else
    {
        Serial.printf("Failed, %s\n", config.signer.signupError.message.c_str());
        isAuthenticated = false;
    }
    // Assign the callback function for the long running token generation task, see addons/TokenHelper.h
    config.token_status_callback = tokenStatusCallback;
    // Initialise the firebase library
    Firebase.begin(&config, &auth);
}

void FirebaseConnect::Firebase_Update()
{
    // Check that 10 seconds has elapsed before, device is authenticated and the firebase service is ready.
    if (millis() - elapsedMillis > update_interval && isAuthenticated && Firebase.ready())
    {
        elapsedMillis = millis();
        Serial.println("------------------------------------");
        Serial.println("Set int test...");
        // Specify the key value for our data and append it to our path
        String node = databasePath + "/value";
        // Send the value our count to the firebase realtime database
        if (Firebase.set(fbdo, node.c_str(), count++))
        {
            // Print firebase server response
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            Serial.println("ETag: " + fbdo.ETag());
            Serial.print("VALUE: ");
            printResult(fbdo); // see addons/RTDBHelper.h
            Serial.println("------------------------------------");
            Serial.println();
        }
        else
        {
            Serial.println("FAILED");
            Serial.println("REASON: " + fbdo.errorReason());
            Serial.println("------------------------------------");
            Serial.println();
        }
    }
}

void FirebaseConnect::Firebase_Update_Temp(float tmp)
{
    // Check that 10 seconds has elapsed before, device is authenticated and the firebase service is ready.
    if (millis() - elapsedMillis > update_interval && isAuthenticated && Firebase.ready())
    {
        elapsedMillis = millis();
        Serial.println("------------------------------------");
        Serial.println("Set int test...");
        // Specify the key value for our data and append it to our path
        String node = databasePath + "/temperature";
        // Send the value our count to the firebase realtime database
        if (Firebase.set(fbdo, node.c_str(), tmp))
        {
            // Print firebase server response
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            Serial.println("ETag: " + fbdo.ETag());
            Serial.print("VALUE: ");
            printResult(fbdo); // see addons/RTDBHelper.h
            Serial.println("------------------------------------");
            Serial.println();
        }
        else
        {
            Serial.println("FAILED");
            Serial.println("REASON: " + fbdo.errorReason());
            Serial.println("------------------------------------");
            Serial.println();
        }
    }
}