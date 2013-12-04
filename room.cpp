#include "room.h"
#include "house.h"
#include "devicefactory.h"
#include "appliancefactory.h"
#include "lightfactory.h"
#include <iostream>
#include <algorithm>

using namespace std;

Room::Room(std::string roomName)
{
    _name = roomName;
    cout << "Added " << _name << endl;
}

Room::~Room()
{

}

void Room::addComponent(std::string componentName)
{
    House *h = House::instance();
    std::vector<Component*> comp = h->getComponents();
    for(std::vector<Component*>::iterator it = comp.begin(); it != comp.end(); ++it)
    {
        Component *c = *it;
        if(c->getName() == componentName)
        {
            cout << "Added " << c->getName() << " to " << this->getName() << endl;
            _components.push_back(c);
        }
    }
}

void Room::removeComponent(std::string componentName)
{
    for(std::vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        Component *c = *it;
        if(c->getName() == componentName)
        {
            cout << "Removing " << c->getName() << " from " << this->getName() << endl;
            _components.erase(std::remove(_components.begin(), _components.end(), c));
            c->~Component();
        }
    }
}

/*
 *This method is called by the "Setup Component Called 'Y'" Command
 */
void Room::setupComponent(TYPES::COMPONENTS componentType, string componentName)
{
    Factory *factory;
    Component *comp;
    switch(componentType){
    case TYPES::DEVICE :
        factory = new DeviceFactory();
        comp = factory->create(componentName);
        _components.push_back(comp);
        break;
    case TYPES::APPLIANCE :
        factory = new ApplianceFactory();
        comp = factory->create(componentName);
        _components.push_back(comp);
        break;
    case TYPES::LIGHT :
        factory = new LightFactory();
        comp = factory->create(componentName);
        _components.push_back(comp);
        break;
    default:
        cerr << "Currently unsupported component" << endl;
        break;
    }
}

void Room::turnOnComponent(std::string componentName)
{
    for(std::vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
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

void Room::turnOnComponents()
{
    for(std::vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        Component *c = *it;
        cout << "Turning on " << c->getName() << endl;
        c->on();
    }
}

void Room::turnOffComponent(std::string componentName)
{
    for(std::vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
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

void Room::turnOffComponents()
{
    for(std::vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        Component *c = *it;
        cout << "Turning off " << c->getName() << endl;
        c->off();
    }
}


std:: string Room::getName()
{
    return _name;
}

void Room::setName(std::string newName)
{
    _name = newName;
}

Memento *Room::createMemento()
{
    return new Memento(_components);
}


void Room::reinstateMemento(Memento *mem)
{
    _components = mem->_state;
}

std::vector<Component *> Room::getComponents()
{
    return _components;
}
