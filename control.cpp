#include "control.h"
#include "turnroomon.h"
#include "turnroomoff.h"
#include "turnhouseoff.h"
#include "turncomponentoff.h"
#include "turncomponenton.h"
#include "addcomponent.h"
#include "removecomponent.h"
#include "setuproom.h"
#include "setupcomponent.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

/*!
 * \brief Control::Control
 * \param h
 */
Control::Control(House *h)
{
    _house = h;
    _help["Info"] = "None of the following commands take or recognise any special characters or punctuation points so refrain from using them.";
    _help["Setup"] = "The setup command allows you to setup a new room or component by entering the command like so:\n\nSetup room:\t\tSetup roomType called livingroom\nSetup component:\t\tSetup componentType called componentName in roomName\nMake sure you place the name of the object at the end of the command.";
    _help["Add"] = "This command allows you to add or register a component with a specific room. To do so ensure you use the following template:\n\n\t\tAdd componentName to roomName\n\nBe sure you follow this template otherwise the command will fail.";
    _help["Remove"] = "Similar to the Add command, this time the Remove command removes or unregisters a component from a room.\nWARNING:\tDo not use this command as it also deletes the components data. The command is:\n\n\t\tRemove componentName from roomName\n\n";
    _help["Turn"] = "This command is divided into three parts, Turn on, Turn off, and Turn house off.";
    _help["Turn on"] = "This command turns individual components as well as entire rooms on by entering the command as follows:\n\nFor rooms:\tTurn roomName on\nFor components:\tTurn roomName componentName on\nMake certain you enter the command as given otherwise you'll get an error.";
    _help["Turn off"] = "Exactly the same as the Turn on command except for the result, which is that the named object is turned off. The command is:\n\nFor rooms:\tTurn roomName off\nFor components:\tTurn roomName componentName off\n";
    _help["Turn house off"] = "This command will turn everything registered to a room off. To do so enter:\n\n\t\tTurn house off\n\nBe sure you enter the command exactly as given otherwise you will encounter na error.";
    _help["Help"] = "Displays this list of commands. Use:\n\n\t\tHelp\n\n";
    _help["Quit"] = "This exits the application. Use:\n\n\t\tQuit\n\n";

    _comments.push_back("What would you like me to do?");
    _comments.push_back("Yes?");
    _comments.push_back("Anything else?");
}

/*!
 * \brief Control::split
 * \param s
 * \param delim
 * \return
 */
std::vector<std::string> Control::split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

/*!
 * \brief Control::split
 * \param s
 * \param delim
 * \param elems
 * \return
 */
std::vector<string> &Control::split(const string &s, char delim, std::vector<string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        std::transform(item.begin(), item.end(), item.begin(), ::tolower);
        elems.push_back(item);
    }
    return elems;
}

/*!
 * \brief Control::jarvisComments
 */
void Control::jarvisComments()
{
    std::cout << _comments.at(rand() % _comments.size()) << std::endl;
}

/*!
 * \brief Control::run
 */
void Control::run()
{
    std::cout << "Welcome. I'm Jarvis your Home Automation System.Please enter a command. To see the list of commands enter help." << std::endl;
    while(true)
    {
        jarvisComments();
        getline(cin, _input);
        _elems = split(_input, _whitespace);
        executeCommands(_elems);
    }
    exit(0);
}

/*!
 * \brief Control::executeCommands
 * \param elems
 * \return
 */
bool Control::executeCommands(std::vector<std::string> elems)
{
    if(std::find(elems.begin(), elems.end(), "quit") != elems.end())
    {
        std::cout << "Exiting the application..." << std::endl;
        exit(0);
    }
    else if(std::find(elems.begin(), elems.end(), "add") != elems.end())
    {
        executeAdd(elems);
    }
    else if(std::find(elems.begin(), elems.end(), "remove") != elems.end())
    {
        executeRemove(elems);
    }
    else if(std::find(elems.begin(), elems.end(), "turn") != elems.end())
    {
        executeTurn(elems);
    }
    else if(std::find(elems.begin(), elems.end(), "setup") != elems.end() && elems.size() == 4)
    {
        executeRoomSetup(elems);
    }
    else if(std::find(elems.begin(), elems.end(), "setup") != elems.end() && elems.size() > 4)
    {
        executeComponentSetup(elems);
    }
    else if(std::find(elems.begin(), elems.end(), "help") != elems.end())
    {
        help();
    }
    else
    {
        std::cerr << "Unknown command given. Please use one of the following: " << endl;
        help();
    }
    return true;
}

/*!
 * \brief Control::executeComponentSetup
 * \param elems
 */
void Control::executeComponentSetup(std::vector<string> elems)
{
    Types *t = new Types();
    std::map<std::string, TYPES::COMPONENTS> cType = t->getComponentTypes();

    for(std::map<std::string, TYPES::COMPONENTS>::const_iterator it = cType.begin(); it != cType.end(); ++it)
    {
        if(std::find(elems.begin(), elems.end(), it->first) != elems.end())
        {
            setupComponent(elems.at(1), elems.back(), it->second);
            break;
        }
    }
}

/*!
 * \brief Control::executeRoomSetup
 * \param elems
 */
void Control::executeRoomSetup(std::vector<std::string> elems)
{
    Types *t = new Types();
    std::map<std::string, TYPES::ROOMS> rType = t->getRoomTypes();

    for(std::map<std::string, TYPES::ROOMS>::const_iterator it = rType.begin(); it != rType.end(); ++it)
    {
        if(std::find(elems.begin(), elems.end(), it->first) != elems.end())
        {
            setupRoom(elems.back(), it->second);
            break;
        }
    }
}

/*!
 * \brief Control::executeAdd
 * \param elems
 */
void Control::executeAdd(std::vector<std::string> elems)
{
    if(elems.size() == 4)
    {
        addComponent(elems.at(1), elems.back());
    }
    else
    {
        std::cerr << "Error: Incorrect command. Please see documentation." << std::endl;
    }
}

/*!
 * \brief Control::executeRemove
 * \param elems
 */
void Control::executeRemove(std::vector<std::string> elems)
{
    if(elems.size() == 4)
    {
        removeComponent(elems.at(1), elems.back());
    }
    else
    {
        std::cerr << "Error: Incorrect command. Please see documentation." << std::endl;
    }
}

/*!
 * \brief Control::executeTurn
 * \param elems
 */
void Control::executeTurn(std::vector<std::string> elems)
{
    if(std::find(elems.begin(), elems.end(), "room") != elems.end() && std::find(elems.begin(), elems.end(), "on") != elems.end())
    {
        turnRoomOn(elems.at(1));
    }
    else if(std::find(elems.begin(), elems.end(), "room") != elems.end() && std::find(elems.begin(), elems.end(), "off") != elems.end())
    {
        turnRoomOff(elems.at(1));
    }
    else if(std::find(elems.begin(), elems.end(), "component") != elems.end() && std::find(elems.begin(), elems.end(), "on") != elems.end())
    {
        turnComponentOn(elems.at(1), elems.at(2));
    }
    else if(std::find(elems.begin(), elems.end(), "component") != elems.end() && std::find(elems.begin(), elems.end(), "on") != elems.end())
    {
        turnComponentOff(elems.at(1), elems.at(2));
    }
    else if(std::find(elems.begin(), elems.end(), "house") != elems.end() && std::find(elems.begin(), elems.end(), "off") != elems.end())
    {
        turnHouseOff();
    }
    else
    {
        std::cerr << "Error: Incorrect command. Please see documentation." << std::endl;
    }
}

/*!
 * \brief Control::help
 */
void Control::help()
{
    std::cout << "\n\n********[HELP]********\n" << std::endl;
    for(std::map<std::string, std::string>::const_iterator it = _help.begin(); it != _help.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

/*!
 * \brief Control::turnRoomOn
 * \param roomName
 */
void Control::turnRoomOn(string roomName)
{
    TurnRoomOn *tro;
    tro = new TurnRoomOn(_house);
    tro->execute(roomName);
}

/*!
 * \brief Control::turnRoomOff
 * \param roomName
 */
void Control::turnRoomOff(string roomName)
{
    TurnRoomOff *troff;
    troff = new TurnRoomOff(_house);
    troff->execute(roomName);
}

/*!
 * \brief Control::turnHouseOff
 */
void Control::turnHouseOff()
{
    TurnHouseOff *thoff;
    thoff = new TurnHouseOff(_house);
    thoff->execute("turning off");
}

/*!
 * \brief Control::removeComponent
 * \param componentName
 * \param roomName
 */
void Control::removeComponent(string componentName, string roomName)
{
    RemoveComponent *rc;
    Room *room = _house->getRoom(roomName);
    rc = new RemoveComponent(room);
    rc->execute(componentName);
}

/*!
 * \brief Control::addComponent
 * \param componentName
 * \param roomName
 */
void Control::addComponent(string componentName, string roomName)
{
    AddComponent *ac;
    Room *room = _house->getRoom(roomName);
    ac = new AddComponent(room);
    ac->execute(componentName);
}

/*!
 * \brief Control::setupComponent
 * \param componentName
 * \param roomName
 * \param compType
 */
void Control::setupComponent(std::string componentName, std::string roomName, TYPES::COMPONENTS compType)
{
    Room *r= _house->getRoom(roomName);
    SetupComponent *sc = new SetupComponent(r, compType);
    sc->execute(componentName);
}

/*!
 * \brief Control::setupRoom
 * \param roomName
 * \param roomType
 */
void Control::setupRoom(std::string roomName, TYPES::ROOMS roomType)
{
    House *h = _house;
    SetupRoom *sr = new SetupRoom(h, roomType);
    sr->execute(roomName);
}

/*!
 * \brief Control::turnComponentOn
 * \param componentName
 * \param roomName
 */
void Control::turnComponentOn(std::string componentName, std::string roomName)
{
    TurnComponentOn *tco;
    Room *room = _house->getRoom(roomName);
    tco = new TurnComponentOn(room);
    tco->execute(componentName);
}

/*!
 * \brief Control::turnComponentOff
 * \param componentName
 * \param roomName
 */
void Control::turnComponentOff(std::string componentName, string roomName)
{
    TurnComponentOff *tcoff;
    Room *room = _house->getRoom(roomName);
    tcoff = new TurnComponentOff(room);
    tcoff->execute(componentName);
}
