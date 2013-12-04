#ifndef LIVINGROOM_H
#define LIVINGROOM_H
#include "room.h"

class LivingRoom: public Room
{
public:
    LivingRoom(std::string name);
    void addComponent(std::string componentName);
    void turnOffComponent(std::string componentName);
    void turnOffComponents();
    void turnOnComponent(std::string componentName);
    void turnOnComponents();
    void removeComponent(std::string componentName);
    void setupComponent(TYPES::COMPONENTS componentType, std::string componentName);
};

#endif // LIVINGROOM_H
