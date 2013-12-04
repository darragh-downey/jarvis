#ifndef APPLIANCE_H
#define APPLIANCE_H
#include "component.h"

class Appliance: public Component
{
public:
    Appliance(std::string applianceName);
    ~Appliance();
    std::string getName();
    void off();
    void on();
    void setCurrent(State *s);
    float getUsage();
    void setUsage(float usage);
};

#endif // APPLIANCE_H
