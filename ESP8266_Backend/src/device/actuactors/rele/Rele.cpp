#include "Rele.h"
#include "Arduino.h"

#include "../include/config.h"

int Rele::Get_Pin()
{
    return USER_SETTINGS_DHT11_PIN;
}

void Rele::Set_Pin()
{
    Serial.print("Set_Pin Rele: ");
    this->pin = USER_SETTINGS_DHT11_PIN;
}

void Rele::Set_Status(bool status)
{
    Serial.print("Set_Status Rele: ");
    this->status = status;
}

bool Rele::Get_Status()
{
    Serial.print("Get_Status Rele: ");
    return this->status;
}

void Rele::Rele_Init()
{   
    pinMode(USER_SETTINGS_RELE_PIN, OUTPUT);
    Serial.println("Rele::Rele_Init()");
}

void Rele::Switch_On()
{
    digitalWrite(USER_SETTINGS_RELE_PIN, HIGH);
    Serial.println("Rele::Switch_On()");
}

void Rele::Switch_Off()
{
    digitalWrite(USER_SETTINGS_RELE_PIN, LOW);
    Serial.println("Rele::Switch_Off()");
}

void Rele::Switch_Toggle()
{
    digitalWrite(USER_SETTINGS_RELE_PIN, !digitalRead(USER_SETTINGS_RELE_PIN));
    Serial.println("Rele::Switch_Toggle()");
}

void Rele::Switch_Status()
{
    Serial.println("Rele::Switch_Status()" + String(digitalRead(USER_SETTINGS_RELE_PIN)));
}