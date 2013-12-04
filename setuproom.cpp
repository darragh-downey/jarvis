#include "setuproom.h"

SetupRoom::SetupRoom(House *h, TYPES::ROOMS roomType)
{
    _house = h;
    _roomType = roomType;
}

void SetupRoom::execute(std::string s)
{
    _house->createRoom(_roomType, s);
}
