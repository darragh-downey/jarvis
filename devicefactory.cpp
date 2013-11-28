#include "devicefactory.h"
#include "device.h"

DeviceFactory::DeviceFactory()
{
}

Component* DeviceFactory::create(std::string name)
{
    return new Device(name);
}
