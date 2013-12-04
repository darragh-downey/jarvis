#ifndef REMOVECOMPONENT_H
#define REMOVECOMPONENT_H
#include "command.h"
#include "room.h"

class RemoveComponent: public Command
{
public:
    RemoveComponent(Room *r);
    void execute(std::string s);
protected:
    Room *_room;
};

#endif // REMOVECOMPONENT_H
