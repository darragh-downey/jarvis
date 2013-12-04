#include "turnroomoff.h"

TurnRoomOff::TurnRoomOff(House *h)
{
    _house = h;
}

void TurnRoomOff::execute(std::string s)
{
    _house->turnRoomOff(s);
}
