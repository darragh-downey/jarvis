#include "memento.h"

using namespace std;

Memento::Memento(std::vector<Component *> components)
{
    _state = components;
}
