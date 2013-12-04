#include "roomfactory.h"
#include "bedroom.h"
#include "kitchen.h"
#include "livingroom.h"


using namespace std;

RoomFactory::RoomFactory()
{
}

Room *RoomFactory::create(TYPES::ROOMS roomType,std::string name)
{
    Room *room;
    switch(roomType){
    case TYPES::BEDROOM :
        room = new Bedroom(name);
        break;
    case TYPES::KITCHEN :
        room = new Kitchen(name);
        break;
    case TYPES::LIVINGROOM :
        room = new LivingRoom(name);
        break;

    }
    return room;
}
