#ifndef LIGHT_H
#define LIGHT_H
#include "component.h"
#include "observer.h"

class Light: public Component, public Observer
{
public:
    Light(std::string lightName);
    ~Light();
    std::string getName();
    float getUsage();
    void off();
    void on();
    void setCurrent(State *s);
};

#endif // LIGHT_H
