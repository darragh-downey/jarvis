#ifndef TURNCOMPONENTOFF_H
#define TURNCOMPONENTOFF_H
#include "command.h"
#include "room.h"

//typedef void(Room:: *Action)(std::string);
class TurnComponentOff: public Command
{
public:
    TurnComponentOff(Room *r);
    void execute(std::string s);
protected:
    Room *_receiver;

  //Action action;
};

#endif // TURNCOMPONENTOFF_H
