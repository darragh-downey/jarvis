#ifndef TURNROOMON_H
#define TURNROOMON_H
#include "command.h"
#include "house.h"

class TurnRoomOn: public Command
{
public:
    TurnRoomOn(House *h);
    void execute(std::string s);
protected:
    House *_house;
};

#endif // TURNROOMON_H
