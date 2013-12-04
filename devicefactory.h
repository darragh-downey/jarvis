#ifndef DEVICEFACTORY_H
#define DEVICEFACTORY_H
#include "factory.h"
#include "device.h"

class DeviceFactory: public Factory
{
public:
    DeviceFactory();
    Device *create(std::string name);
};

#endif // DEVICEFACTORY_H
