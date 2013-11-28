#ifndef DEVICE_H
#define DEVICE_H
#include "component.h"

class Device: public Component
{
public:
    Device(std::string deviceName);
    ~Device();
    std::string getName();
    float getUsage();
    void off();
    void on();
    void setCurrent(State *s);
};

#endif // DEVICE_H
