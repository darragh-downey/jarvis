#ifndef ADDCOMPONENT_H
#define ADDCOMPONENT_H
#include "command.h"
#include "room.h"

class AddComponent: public Command
{
public:
    AddComponent(Room *r);
    void execute(std::string s);
protected:
    Room *_room;
};

#endif // ADDCOMPONENT_H
