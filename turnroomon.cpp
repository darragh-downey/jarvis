#include "turnroomon.h"

TurnRoomOn::TurnRoomOn(House *h)
{
    _house = h;
}

void TurnRoomOn::execute(std::string s)
{
    _house->turnRoomOn(s);
}
