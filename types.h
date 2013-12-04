#ifndef TYPES_H
#define TYPES_H
#include <map>
#include <string>

struct TYPES{
    enum ROOMS{
        KITCHEN, LIVINGROOM, BEDROOM
    };

    enum COMPONENTS{
        DEVICE, APPLIANCE, LIGHT
    };
};

class Types
{  
public:
    Types();
    std::map<std::string, TYPES::ROOMS> getRoomTypes();
    std::map<std::string, TYPES::COMPONENTS> getComponentTypes();
protected:
    std::map<std::string, TYPES::ROOMS> roomTypes;
    std::map<std::string, TYPES::COMPONENTS> componentTypes;
};

#endif // TYPES_H
