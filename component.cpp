#include "component.h"
#include "off.h"
#include <iostream>

using namespace std;

/*!
 * \brief Component::Component
 */
Component::Component()
{
}

/*!
 * \brief Component::~Component
 */
Component::~Component()
{
}

/*!
 * \brief Component::getName
 * \return
 */
std::string Component::getName()
{
    return name;
}

/*!
 * \brief Component::setCurrent
 * \param s
 */
void Component::setCurrent(State *s)
{
    current = s;
}

/*!
 * \brief Component::setUsage
 * \param usage
 */
void Component::setUsage(float usage)
{
    kWatts = usage;
}

/*!
 * \brief Component::getUsage
 * \return
 */
float Component::getUsage()
{
    return kWatts;
}

/*!
 * \brief Component::on
 */
void Component::on()
{
}

/*!
 * \brief Component::off
 */
void Component::off()
{
}

