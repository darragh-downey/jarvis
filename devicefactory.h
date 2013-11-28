#ifndef DEVICEFACTORY_H
#define DEVICEFACTORY_H
#include "factory.h"

class DeviceFactory: public Factory
{
public:
    DeviceFactory();
    Component* create(std::string name);
};

#endif // DEVICEFACTORY_H
