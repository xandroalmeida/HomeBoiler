#include "TemperatureSensors.h"

TemperatureSensors::TemperatureSensors(OneWire* oneWire) : 
    _dallasTemperature(new DallasTemperature(oneWire)),
    _devicesAddress(),
    _ticker()
{

}

TemperatureSensors::~TemperatureSensors()
{
    delete this->_dallasTemperature;
    this->_dallasTemperature = nullptr;
}

void TemperatureSensors::init()
{
     this->_dallasTemperature->begin();
     uint8_t deviceCount = this->_dallasTemperature->getDeviceCount();
     for (uint8_t n = 0; n < deviceCount; n++) {
         DeviceAddress address;
        if (this->_dallasTemperature->getAddress(address, n) && this->_dallasTemperature->validFamily(address)) {
            this->_devicesAddress.push_front(address);
        }
     }
}

void TemperatureSensors::start() 
{
    
}