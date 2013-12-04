#include "bedroom.h"

using namespace std;

/*!
 * \brief Bedroom::Bedroom
 * \param name
 */
Bedroom::Bedroom(std::string name): Room(name)
{
    _name = name;
}

/*!
 * \brief Bedroom::addComponent
 * \param componentName
 */
void Bedroom::addComponent(std::string componentName)
{
    Room::addComponent(componentName);
}

/*!
 * \brief Bedroom::turnOffComponent
 * \param componentName
 */
void Bedroom::turnOffComponent(std::string componentName)
{
    Room::turnOffComponent(componentName);
}

/*!
 * \brief Bedroom::turnOffComponents
 */
void Bedroom::turnOffComponents()
{
    Room::turnOffComponents();
}

/*!
 * \brief Bedroom::turnOnComponent
 * \param componentName
 */
void Bedroom::turnOnComponent(std::string componentName)
{
    Room::turnOnComponent(componentName);
}

/*!
 * \brief Bedroom::turnOnComponents
 */
void Bedroom::turnOnComponents()
{
    Room::turnOnComponents();
}

/*!
 * \brief Bedroom::removeComponent
 * \param componentName
 */
void Bedroom::removeComponent(std::string componentName)
{
    Room::removeComponent(componentName);
}

/*!
 * \brief Bedroom::setupComponent
 * \param componentType
 * \param componentName
 */
void Bedroom::setupComponent(TYPES::COMPONENTS componentType, std::string componentName)
{
    Room::setupComponent(componentType, componentName);
}
