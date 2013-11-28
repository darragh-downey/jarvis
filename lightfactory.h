#ifndef LIGHTFACTORY_H
#define LIGHTFACTORY_H
#include "factory.h"

class LightFactory: public Factory
{
public:
    LightFactory();
    Component* create(std::string name);
};

#endif // LIGHTFACTORY_H
