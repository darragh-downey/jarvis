#include "house.h"
#include "roomfactory.h"
#include <iostream>

using namespace std;
/*!
 * \brief House::_houseInstance
 *  Global static pointer to ensure a single instance of the class.
 */
House *House::_houseInstance = NULL;

House::House()
{
}

House::~House()
{

}

/*!
 * \brief House::instance
 * \return House instance
 *  Ensures only a single instance of House exists at any one time.
 */
House *House::instance()
{
    if(!_houseInstance)
        _houseInstance = new House();
    return _houseInstance;
}

/*
 *This method is called by "Setup Room Called 'X'" Command
 */
void House::createRoom(TYPES::ROOMS roomType, std::string roomName)
{
    RoomFactory *rf = new RoomFactory;
    Room *room = rf->create(roomType, roomName);
    cout << "Setup " << room->getName() << endl;
    _rooms.push_back(room);
}

/*
 *This method is called by "Turn Room 'X' On"
 */
void House::turnRoomOn(std::string roomName)
{
    for(std::vector<Room *>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
        Room *r = *it;
        if(r->getName() == roomName)
        {
            cout << "Turning on components in " << r->getName() << endl;
            r->turnOnComponents();
        }
    }
}

/*
 *This method is called by "Turn Room 'X' Off"
 */
void House::turnRoomOff(std::string roomName)
{
    for(std::vector<Room *>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
        Room *r = *it;
        if(r->getName() == roomName)
        {
            cout << "Turning off components in " << r->getName() << endl;
            r->turnOffComponents();
        }
    }
}

/*
 *This method is called by "Turn House Off"
 */
void House::turnHouseOff()
{
    cout << "Turning off all components!" << endl;
    for(std::vector<Room *>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
        Room *r = *it;
        r->turnOffComponents();
    }
}

std::vector<Component *> House::getComponents()
{
    std::vector<Component *> components;
    for(std::vector<Room *>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
        Room *r = *it;
        components = r->getComponents();
    }
    return components;
}

Room *House::getRoom(std::string roomName)
{
    for(std::vector<Room *>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
        Room *r = *it;
        if(r->getName() == roomName)
            return r;
    }
}
