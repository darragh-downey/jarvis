#include "device.h"
#include "off.h"
#include <iostream>

using namespace std;

Device::Device(std::string deviceName)
{
    name = deviceName;
    current = new Off();
    cout << "Added " << name << " device" << "\n";
}

Device::~Device()
{
    cout << "Deleting " << this->getName() << endl;
    delete current;
}

std::string Device::getName()
{
    return name;
}

void Device::setCurrent(State *s)
{
    current = s;
}

void Device::on()
{
    current->on(this);
}

void Device::off()
{
    current->off(this);
}

float Device::getUsage()
{
    return kWatts;
}

void Device::setUsage(float usage)
{
    kWatts = usage;
}
