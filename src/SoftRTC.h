#ifndef __SOFTRTC_H__
#define __SOFTRTC_H__

#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Ticker.h>

class SoftRTC {
    SoftRTC();
    virtual ~SoftRTC();
    friend void updateNTP(SoftRTC*);
private:
    WiFiUDP _ntpUDP;
    NTPClient _timeClient;
    Ticker _ticker;
};

#endif
