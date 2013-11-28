#ifndef STATE_H
#define STATE_H
#include "component.h"

class Component;

class State
{
public:
    State();
    virtual ~State();
    virtual void on(Component *c);
    virtual void off(Component *c);
};

#endif // STATE_H
