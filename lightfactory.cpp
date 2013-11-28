#include "lightfactory.h"
#include "light.h"

LightFactory::LightFactory()
{
}

Component* LightFactory::create(std::string name)
{
    return new Light(name);
}
