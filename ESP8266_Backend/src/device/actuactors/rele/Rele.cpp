#include "Rele.h"
#include "Arduino.h"

int Rele::Get_Pin()
{
    return this->pin;
}

void Rele::Set_Pin(int pin)
{
    Serial.print("Set_Pin Rele: ");
    this->pin = pin;
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

void Rele::Rele_Init(int pin)
{   
    Set_Pin(pin);
    pinMode(this->pin, OUTPUT);
    Serial.println("Rele::Rele_Init()");
}

void Rele::Switch_On()
{
    digitalWrite(this->pin, HIGH);
    Serial.println("Rele::Switch_On()");
}

void Rele::Switch_Off()
{
    digitalWrite(this->pin, LOW);
    Serial.println("Rele::Switch_Off()");
}

void Rele::Switch_Toggle()
{
    digitalWrite(this->pin, !digitalRead(this->pin));
    Serial.println("Rele::Switch_Toggle()");
}

void Rele::Switch_Status()
{
    Serial.println("Rele::Switch_Status()");

    if (digitalRead(this->pin) == HIGH)
    {
        Serial.println("Rele::Switch_Status() - HIGH");
    }
    else
    {
        Serial.println("Rele::Switch_Status() - LOW");
    }
}