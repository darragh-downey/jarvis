#include "kitchen.h"

using namespace std;

Kitchen::Kitchen(std::string name): Room(name)
{
    _name = name;
}

void Kitchen::addComponent(std::string componentName)
{
    for(std::vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        Component *c = *it;
        if(c->getName() == componentName)
            _components.push_back(c);
    }
}

void Kitchen::turnOffComponent(std::string componentName)
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

void Kitchen::turnOffComponents()
{
    for(std::vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        Component *c = *it;
        cout << "Turning off " << c->getName() << endl;
        c->off();
    }
}

void Kitchen::turnOnComponent(std::string componentName)
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

void Kitchen::turnOnComponents()
{
    for(std::vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        Component *c = *it;
        cout << "Turning on " << c->getName() << endl;
        c->on();
    }
}

void Kitchen::removeComponent(std::string componentName)
{
    for(std::vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        Component *c = *it;
        if(c->getName() == componentName)
        {
            c->~Component();
        }
    }
}

void Kitchen::setupComponent(TYPES::COMPONENTS componentType, std::string componentName)
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
        cout << "Currently unsupported" << endl;
        break;
    }
}
