#ifndef APPLIANCEFACTORY_H
#define APPLIANCEFACTORY_H
#include "factory.h"

class ApplianceFactory: public Factory
{
public:
    ApplianceFactory();
    Component* create(std::string name);
};

#endif // APPLIANCEFACTORY_H
