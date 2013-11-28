#include "appliancefactory.h"
#include "appliance.h"

ApplianceFactory::ApplianceFactory()
{
}

Component* ApplianceFactory::create(std::string name)
{
    return new Appliance(name);
}
