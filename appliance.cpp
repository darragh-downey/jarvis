#include "appliance.h"
#include "off.h"
#include <iostream>

using namespace std;

Appliance::Appliance(std::string applianceName)
{
    name = applianceName;
    current = new Off();
    cout << "Added " << name << " appliance" << "\n";
}

Appliance::~Appliance()
{
    cout << "Deleting " << this->getName() << endl;
    delete current;
}

std::string Appliance::getName()
{
    return name;
}

void Appliance::off()
{
    current->off(this);
}

void Appliance::on()
{
    current->on(this);
}

float Appliance::getUsage()
{
    return kWatts;
}


void Appliance::setCurrent(State *s)
{
    current = s;
}
