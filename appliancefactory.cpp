#include "appliancefactory.h"
#include "appliance.h"

/*!
 * \brief ApplianceFactory::ApplianceFactory
 */
ApplianceFactory::ApplianceFactory()
{
}

/*!
 * \brief ApplianceFactory::create
 * \param name
 * \return
 */
Appliance *ApplianceFactory::create(std::string name)
{
    return new Appliance(name);
}
