#include "Firebase.h"
#include <SD.h>
#include <Arduino.h>
#include <Firebase_ESP_Client.h>
#include <Wire.h>

// Provide the token generation process info.
#include "addons/TokenHelper.h"
// Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
#include "../include/config.h"
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
// Variable to save USER UID
String uid;
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
    delay(1000);
    // Assign the api key (required)
    config.api_key = API_KEY;
    // Assign the user sign in credentials
    auth.user.email = USER_EMAIL;
    auth.user.password = USER_PASSWORD;
    // configure firebase realtime database url
    config.database_url = DATABASE_URL;
    Firebase.reconnectWiFi(true);
    fbdo.setResponseSize(4096);
    // Assign the callback function for the long running token generation task
    config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
    // Assign the maximum retry of token generation
    config.max_token_generation_retry = 5;
    // Initialize the library with the Firebase authen and config
    Firebase.begin(&config, &auth);
    //Getting the user UID might take a few seconds
    Serial.println("Getting User UID");
    while ((auth.token.uid) == "")
    {
        Serial.print('.');
        Firebase.begin(&config, &auth);
        Serial.println(Firebase.authenticated());
        delay(1000);
    }
    // Print user UID
    
    Serial.print("User UID: ");
    Serial.print(uid);
    Serial.println("------------------------------------");
    Serial.println("Sign up new user...");
    // Sign in to firebase Anonymously
    if (Firebase.signUp(&config, &auth, "", ""))
    {
        Serial.println("Success");
        uid = auth.token.uid.c_str();
        isAuthenticated = true;
        // Set the database path where updates will be loaded for this device
        databasePath = "/" + device_location;
        uid = auth.token.uid.c_str();
    }
    else
    {
        Serial.printf("Failed, %s\n", config.signer.signupError.message.c_str());
        isAuthenticated = false;
    }
    // Assign the callback function for the long running token generation task, see addons/TokenHelper.h
    config.token_status_callback = tokenStatusCallback;

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
        if (Firebase.RTDB.setFloat(&fbdo, node.c_str(), count))
        {
            Serial.println("Success");
            // Increment the count
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
        if (Firebase.RTDB.setFloat(&fbdo, node.c_str(), tmp))
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