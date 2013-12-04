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
    virtual std::string getName();
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void setCurrent(State *s);
    virtual float getUsage();
    virtual void setUsage(float usage);
protected:
    std::string name;
    float kWatts;
    State *current;
    //std::vector<Observer*> links;

};

#endif // COMPONENT_H
