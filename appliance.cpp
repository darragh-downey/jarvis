#include "appliance.h"
#include "off.h"
#include <iostream>

using namespace std;

/*!
 * \brief Appliance::Appliance
 * \param applianceName
 */
Appliance::Appliance(std::string applianceName)
{
    name = applianceName;
    current = new Off();
    cout << "Added " << this->getName() << " appliance" << endl;
}

/*!
 * \brief Appliance::~Appliance
 */
Appliance::~Appliance()
{
    cout << "Deleting " << this->getName() << endl;
    delete current;
}

/*!
 * \brief Appliance::getName
 * \return
 */
std::string Appliance::getName()
{
    return name;
}

/*!
 * \brief Appliance::off
 */
void Appliance::off()
{
    current->off(this);
}

/*!
 * \brief Appliance::on
 */
void Appliance::on()
{
    current->on(this);
}

/*!
 * \brief Appliance::getUsage
 * \return
 */
float Appliance::getUsage()
{
    return kWatts;
}

/*!
 * \brief Appliance::setUsage
 * \param usage
 */
void Appliance::setUsage(float usage)
{
    kWatts = usage;
}

/*!
 * \brief Appliance::setCurrent
 * \param s
 */
void Appliance::setCurrent(State *s)
{
    current = s;
}
