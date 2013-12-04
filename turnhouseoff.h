#ifndef TURNHOUSEOFF_H
#define TURNHOUSEOFF_H
#include "house.h"

class TurnHouseOff
{
public:
    TurnHouseOff(House *h);
    void execute(std::string s);
protected:
    House *_house;
};

#endif // TURNHOUSEOFF_H
