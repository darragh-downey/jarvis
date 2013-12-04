#include "light.h"
#include "off.h"
#include <iostream>

using namespace std;

Light::Light(std::string lightName)
{
    name = lightName;
    current = new Off();
    cout << "Added " << name << "light" << "\n";
}

Light::~Light()
{
    cout << "Deleting " << this->getName() << endl;
    delete current;
}

std::string Light::getName()
{
    return name;
}

void Light::setCurrent(State *s)
{
    current = s;
}

void Light::on()
{
    current->on(this);
}

void Light::off()
{
    current->off(this);
}

float Light::getUsage()
{
    return kWatts;
}

void Light::setUsage(float usage)
{
    kWatts = usage;
}
