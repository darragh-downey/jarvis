#include "turncomponentoff.h"

TurnComponentOff::TurnComponentOff(Room *r)
{
   // action = meth;
    _receiver = r;
}

void TurnComponentOff::execute(std::string s)
{
    _receiver->turnOffComponent(s);
    //(_receiver->*action)(s);
      //      turnOffComponent(s);
}
