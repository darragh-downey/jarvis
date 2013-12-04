#include "turnhouseoff.h"

TurnHouseOff::TurnHouseOff(House *h)
{
    _house = h;
}

void TurnHouseOff::execute(std::string s)
{
    _house->turnHouseOff();
}
