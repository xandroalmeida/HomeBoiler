#ifndef __TEMPERATURESENSORBUS_H__
#define __TEMPERATURESENSORBUS_H__

#include "Ticker.h"
#include <list>
#include <DallasTemperature.h>

class TemperatureSensors {
public:
    TemperatureSensors(OneWire* oneWire);
    virtual ~TemperatureSensors();
    void init();
    void start();
private:
    DallasTemperature* _dallasTemperature;
    std::list<uint8_t*> _devicesAddress;
    Ticker _ticker;
};

#endif
