#include <SoftRTC.h>

SoftRTC::SoftRTC() :
    _ntpUDP(),
    _timeClient(_ntpUDP),
    _ticker()
{
    this->_timeClient.begin();
    this->_ticker.attach(60*5, updateNTP, this);
}

SoftRTC::~SoftRTC()
{
}

void updateNTP(SoftRTC* softRTC) 
{
    softRTC->_timeClient.update();
}