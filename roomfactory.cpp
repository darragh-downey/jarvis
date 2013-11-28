#include "roomfactory.h"

using namespace std;

RoomFactory::RoomFactory()
{
}

Room *RoomFactory::create(std::string name)
{
    return new Room(name);
}
