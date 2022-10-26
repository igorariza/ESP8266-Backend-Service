#include "RtcDs.h"
#include "Arduino.h"
#include "../include/config.h"
#include <RTClib.h> // for the RTC
#include <Wire.h>

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void RtcDs(){};

void RtcDs::RtcInit()
{
  uint8_t sda = RTC_SDA;
  uint8_t scl = RTC_SCL;
  Wire.begin(sda, scl);
  if (!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    while (1)
      ;
  }
  if (rtc.lostPower())
  {
    Serial.println("RTC lost power, lets set the time!");
    delay(1000);
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
};

String RtcDs::RtcRead()
{
  DateTime now = rtc.now();
  String rtcTime = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
  String rtcDate = String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());
  return rtcTime + " " + rtcDate;
};

String RtcDs::getRtcTime()
{
  DateTime now = rtc.now();
  String rtcTime = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
  return rtcTime;
};

String RtcDs::getTemperature()
{
  float t = rtc.getTemperature();
  String temperature = String(t);
  return temperature;
};