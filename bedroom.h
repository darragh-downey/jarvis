#ifndef BEDROOM_H
#define BEDROOM_H
#include "room.h"

class Bedroom: public Room
{
public:
    Bedroom(std::string name);
    void addComponent(std::string componentName);
    void turnOffComponent(std::string componentName);
    void turnOffComponents();
    void turnOnComponent(std::string componentName);
    void turnOnComponents();
    void removeComponent(std::string componentName);
    void setupComponent(TYPES::COMPONENTS componentType, std::string componentName);
};

#endif // BEDROOM_H
