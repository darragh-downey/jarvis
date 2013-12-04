#ifndef MEMENTO_H
#define MEMENTO_H
#include "component.h"
#include <vector>

class Memento
{
public:
    Memento(std::vector<Component *> components);
protected:
    std::vector<Component *> _state;
    friend class Room;
};

#endif // MEMENTO_H
