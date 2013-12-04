#include "livingroom.h"

LivingRoom::LivingRoom(std::string name): Room(name)
{
}

void LivingRoom::addComponent(std::string componentName)
{
    Room::addComponent(componentName);
}

void LivingRoom::turnOffComponent(std::string componentName)
{
    Room::turnOffComponent(componentName);
}

void LivingRoom::turnOffComponents()
{
    Room::turnOffComponents();
}

void LivingRoom::turnOnComponent(std::string componentName)
{
    Room::turnOnComponent(componentName);
}

void LivingRoom::turnOnComponents()
{
    Room::turnOnComponents();
}

void LivingRoom::removeComponent(std::string componentName)
{
    Room::removeComponent(componentName);
}

void LivingRoom::setupComponent(TYPES::COMPONENTS componentType, std::string componentName)
{
    Room::setupComponent(componentType, componentName);
}
