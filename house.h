#ifndef HOUSE_H
#define HOUSE_H
#include "room.h"
#include "types.h"

class House
{
public:
    static House *instance();
    void createRoom(TYPES::ROOMS roomType, std::string roomName);
    void turnRoomOn(std::string roomName);
    void turnRoomOff(std::string roomName);
    void turnHouseOff();
    std::vector<Component *> getComponents();
    Room *getRoom(std::string roomName);
protected:
    House();
    ~House();
    static House *_houseInstance;
    std::vector<Room *> _rooms;
    std::string _objectName;
};

#endif // HOUSE_H
