#ifndef FIREBASE_H_
#define FIREBASE_H_
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

#endif /* FIREBASE_H_ */