#include "lightfactory.h"
#include "light.h"

LightFactory::LightFactory()
{
}

Light *LightFactory::create(std::string name)
{
    return new Light(name);
}
