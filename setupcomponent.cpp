#include "setupcomponent.h"

SetupComponent::SetupComponent(Room *r, TYPES::COMPONENTS compType)
{
    _room = r;
    _compType = compType;
}

void SetupComponent::execute(std::string s)
{
    _room->setupComponent(_compType, s);
}
