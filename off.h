#ifndef OFF_H
#define OFF_H
#include "state.h"

class Off: public State
{
public:
    Off();
    ~Off();
    void on(Component *c);
};

#endif // OFF_H
