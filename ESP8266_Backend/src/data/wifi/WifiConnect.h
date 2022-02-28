#ifndef WIFICONNECT_H
#define WIFICONNECT_H
#include "Arduino.h"

class WifiConnect
{
public:
  WifiConnect();
  void wifi_Init();
  void status_Wifi();
};

#endif