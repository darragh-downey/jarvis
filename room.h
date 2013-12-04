#ifndef ROOM_H
#define ROOM_H
#include "component.h"
#include "memento.h"
#include "types.h"
#include "factory.h"
#include "devicefactory.h"
#include "appliancefactory.h"
#include "lightfactory.h"
#include <vector>
#include <iostream>

class Room
{
public:
    Room(std::string roomName);
    ~Room();
    virtual void addComponent(std::string componentName);
    std::string getName();
    virtual void turnOnComponent(std::string componentName) = 0;
    virtual void turnOffComponent(std::string componentName) = 0;
    virtual void turnOffComponents() = 0;
    virtual void turnOnComponents() = 0;
    virtual void setName(std::string newName);
    Memento *createMemento();
    virtual void reinstateMemento(Memento *mem);
    virtual void removeComponent(std::string componentName) = 0;
    virtual void setupComponent(TYPES::COMPONENTS componentType, std::string componentName);
    std::vector<Component *> getComponents();
protected:
    std::string _name;
    std::vector<Component*> _components;
};

#endif // ROOM_H
