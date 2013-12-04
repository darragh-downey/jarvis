#ifndef USERINPUT_H
#define USERINPUT_H
#include <string>
#include <vector>
#include "command.h"
#include "house.h"
#include "room.h"
#include "types.h"


class Control
{
public:
    Control(House *h);
    std::vector<std::string> split(const std::string &s, char delim);
    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
    void run();
    void turnRoomOn(std::string roomName);
    void turnRoomOff(std::string roomName);
    void turnHouseOff();
    void removeComponent(std::string componentName, std::string roomName);
    void addComponent(std::string componentName, std::string roomName);
    bool executeCommands(std::vector<std::string> elems);
    void setupRoom(std::string roomName, TYPES::ROOMS roomType);
    void help();
    void executeComponentSetup(std::vector<std::string> elems);
    void executeAdd(std::vector<std::string> elems);
    void executeRemove(std::vector<std::string> elems);
    void executeTurn(std::vector<std::string> elems);
    void turnComponentOn(std::string componentName, std::string roomName);
    void turnComponentOff(std::string componentName, std::string roomName);
    void executeRoomSetup(std::vector<std::string> elems);
    void setupComponent(std::string componentName, std::string roomName, TYPES::COMPONENTS compType);
    void jarvisComments();
protected:
    std::map<std::string, Command *> commands;
    std::map<std::string, std::string> _help;
    std::vector<std::string> _comments;
    std::string _input;
    std::vector<std::string> _elems;
    char _whitespace = ' ';
    House *_house;
    Room *_room;
};

#endif // USERINPUT_H
