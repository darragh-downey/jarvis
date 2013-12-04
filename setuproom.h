#ifndef SETUPROOM_H
#define SETUPROOM_H
#include "command.h"
#include "house.h"

class SetupRoom: public Command
{
public:
    SetupRoom(House *h, TYPES::ROOMS roomType);
    void execute(std::string s);
protected:
    TYPES::ROOMS _roomType;
    House *_house;
};

#endif // SETUPROOM_H
