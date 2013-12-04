#ifndef APPLIANCEFACTORY_H
#define APPLIANCEFACTORY_H
#include "factory.h"
#include "appliance.h"

class ApplianceFactory: public Factory
{
public:
    ApplianceFactory();
    Appliance *create(std::string name);
};

#endif // APPLIANCEFACTORY_H
