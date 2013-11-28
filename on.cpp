#include "on.h"
#include "off.h"
#include <iostream>

using namespace std;

On::On()
{
    cout << " ON ctor\n" << endl;
}

On::~On()
{
    cout << "ON d-tor\n" << endl;
}

void On::off(Component *c)
{
    c->setCurrent(new Off());
    delete this;
}
