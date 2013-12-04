#ifndef SETUPCOMPONENT_H
#define SETUPCOMPONENT_H
#include "command.h"
#include "types.h"
#include "room.h"

class SetupComponent: public Command
{
public:
    SetupComponent(Room *r, TYPES::COMPONENTS compType);
    void execute(std::string s);
protected:
    TYPES::COMPONENTS _compType;
    Room *_room;
};

#endif // SETUPCOMPONENT_H
