#ifndef LIGHT_H
#define LIGHT_H
#include "component.h"

class Light: public Component
{
public:
    Light(std::string lightName);
    ~Light();
    std::string getName();
    float getUsage();
    void off();
    void on();
    void setCurrent(State *s);
    void setUsage(float usage);
};

#endif // LIGHT_H
