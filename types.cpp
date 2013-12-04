#include "types.h"

Types::Types()
{
    roomTypes["kitchen"] = TYPES::KITCHEN;
    roomTypes["livingroom"] = TYPES::LIVINGROOM;
    roomTypes["bedroom"] = TYPES::BEDROOM;

    componentTypes["device"] = TYPES::DEVICE;
    componentTypes["appliance"] = TYPES::APPLIANCE;
    componentTypes["light"] = TYPES::LIGHT;
}

std::map<std::string, TYPES::ROOMS> Types::getRoomTypes()
{
    return roomTypes;
}

std::map<std::string, TYPES::COMPONENTS> Types::getComponentTypes()
{
    return componentTypes;
}
