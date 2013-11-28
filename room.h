#ifndef ROOM_H
#define ROOM_H
#include "component.h"
#include <vector>

class Room
{
public:
    Room(std::string roomName);
    void addComponent(Component *c);
    std::string getName();
    void turnOnComponent(std::string componentName);
    void turnOffComponent(std::string componentName);
    void turnOffComponent();
    void turnOnComponent();
    void removeComponent(Component *c);
protected:
    std::string name;
    std::vector<Component*> components;
};

#endif // ROOM_H
