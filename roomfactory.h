#ifndef ROOMFACTORY_H
#define ROOMFACTORY_H
#include <string>
#include "room.h"
#include "types.h"

class RoomFactory
{
public:
    RoomFactory();
    Room *create(TYPES::ROOMS roomType, std::string name);
};

#endif // ROOMFACTORY_H
