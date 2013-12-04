#include "devicefactory.h"
#include "device.h"

DeviceFactory::DeviceFactory()
{
}

Device *DeviceFactory::create(std::string name)
{
    return new Device(name);
}
