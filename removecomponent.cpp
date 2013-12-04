#include "removecomponent.h"

RemoveComponent::RemoveComponent(Room *r)
{
    _room = r;
}

void RemoveComponent::execute(std::string s)
{
    _room->removeComponent(s);
}
