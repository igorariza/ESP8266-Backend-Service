#ifndef WIFICONNECT_H
#define WIFICONNECT_H
#include "Arduino.h"

class WifiConnect
{
public:
  WifiConnect();
  void wifi_Init();
  int status_Wifi();
  void wifi_reconnect();
};

#endif