#ifndef RTCDS_H_
#define RTCDS_H_
#include "Arduino.h"

class RtcDs
{
public:
    RtcDs();
    void RtcInit();
    String RtcRead();
    String getRtcTime();
    String getRtcDate();
};

#endif /* RTCDS3231_H_ */