#include "RtcDS.h"
#include "Arduino.h"
#include "../include/config.h"
#include <RTClib.h> // for the RTC
#include <Wire.h>

RTC_DS3231 rtc;  //  rtc class

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


void RtcDs() {}

void RtcDs::RtcInit()
{
    if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // If the RTC have lost power it will sets the RTC to the date & time this sketch was compiled in the following line
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // set time from computer time
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

String RtcDs::RtcRead()
{
    DateTime now = rtc.now();
    String rtcTime = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
    String rtcDate = String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());
    return rtcTime + " " + rtcDate;
}