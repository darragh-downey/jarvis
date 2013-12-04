#ifndef TURNCOMPONENTON_H
#define TURNCOMPONENTON_H
#include "command.h"
#include "room.h"

class TurnComponentOn: public Command
{
public:
    TurnComponentOn(Room *r);
    void execute(std::string s);
protected:
    Room *_room;
};

#endif // TURNCOMPONENTON_H
