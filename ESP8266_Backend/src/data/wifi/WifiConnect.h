#ifndef WIFICONNECT_H_
#define WIFICONNECT_H_
#include "Arduino.h"

class WifiConnect
{
public:
  WifiConnect();
  void wifi_Init();
  int status_Wifi();
  void wifi_reconnect();
};

#endif /* WIFICONNECT_H_ */