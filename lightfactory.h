#ifndef LIGHTFACTORY_H
#define LIGHTFACTORY_H
#include "factory.h"
#include "light.h"

class LightFactory: public Factory
{
public:
    LightFactory();
    Light *create(std::string name);
};

#endif // LIGHTFACTORY_H
