#include "turncomponenton.h"

TurnComponentOn::TurnComponentOn(Room *r)
{
    _room = r;
}

void TurnComponentOn::execute(std::string s)
{
    _room->turnOnComponent(s);
}
