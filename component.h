#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include "state.h"

class State;

class Component
{
public:
    Component();
    ~Component();
    virtual std::string getName() = 0;
    virtual void on();
    virtual void off();
    virtual void setCurrent(State *s);
    virtual float getUsage() = 0;
protected:
    std::string name;
    float kWatts;
    State *current;
    //std::vector<Observer*> links;

};

#endif // COMPONENT_H
