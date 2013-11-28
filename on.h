#ifndef ON_H
#define ON_H
#include "state.h"

class On: public State
{
public:
    On();
    ~On();
    void off(Component *c);
};

#endif // ON_H
