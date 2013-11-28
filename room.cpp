#include "room.h"
#include <iostream>

using namespace std;

Room::Room(std::string roomName)
{
    name = roomName;
    cout << "Added " << name << endl;
}

void Room::addComponent(Component *c)
{
    components.push_back(c);
}

void Room::removeComponent(Component *c)
{
    for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
        Component *cm = *it;
        if(c == cm)
        {
            c->~Component();
        }
    }
}

void Room::turnOnComponent(std::string componentName)
{
    for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
        Component *c = *it;
        if(c->getName().compare(componentName))
        {
            cout << "Turning on " << c->getName() << endl;
            c->on();
            break;
        }
    }
}

void Room::turnOnComponent()
{
    for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
        Component *c = *it;
        cout << "Turning on " << c->getName() << endl;
        c->on();
    }
}

void Room::turnOffComponent(std::string componentName)
{
    for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
        Component *c = *it;
        if(c->getName().compare(componentName))
        {
            cout << "Turning off " << c->getName() << endl;
            c->off();
            break;
        }
    }
}

void Room::turnOffComponent()
{
    for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
        Component *c = *it;
        cout << "Turning off " << c->getName() << endl;
        c->off();
    }
}


std:: string Room::getName()
{
    return name;
}
