#ifndef TURNROOMOFF_H
#define TURNROOMOFF_H
#include "house.h"

class TurnRoomOff
{
public:
    TurnRoomOff(House *h);
    void execute(std::string s);
protected:
    House *_house;
};

#endif // TURNROOMOFF_H
