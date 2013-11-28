#ifndef ROOMFACTORY_H
#define ROOMFACTORY_H
#include <string>
#include "room.h"

class RoomFactory
{
public:
    RoomFactory();
    Room* create(std::string name);
};

#endif // ROOMFACTORY_H
