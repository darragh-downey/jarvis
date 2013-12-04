#ifndef KITCHEN_H
#define KITCHEN_H
#include "room.h"

class Kitchen: public Room
{
public:
    Kitchen(std::string name);
    void addComponent(std::string componentName);
    void turnOffComponent(std::string componentName);
    void turnOffComponents();
    void turnOnComponent(std::string componentName);
    void turnOnComponents();
    void removeComponent(std::string componentName);
    void setupComponent(TYPES::COMPONENTS componentType, std::string componentName);
};

#endif // KITCHEN_H
