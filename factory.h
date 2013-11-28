#ifndef FACTORY_H
#define FACTORY_H
#include <string>
#include "component.h"

class Factory
{
public:
    Factory();
    virtual Component* create(std::string name) = 0;
protected:
    Component* component;
};

#endif // FACTORY_H
