#ifndef FIREBASE_H
#define FIREBASE_H
#include "Arduino.h"

class FirebaseConnect
{
public:
  FirebaseConnect();
  void Firebase_Init();
  void Firebase_Update();
  void Firebase_Update_Temp(float tmp);
  void Firebase_Update_Humidity(float hum);
  void Firebase_Update_Light(float light);
};

#endif