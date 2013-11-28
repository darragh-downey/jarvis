#include "off.h"
#include "on.h"
#include <iostream>

using namespace std;

Off::Off()
{
    cout << "OFF ctor\n" << endl;
}

Off::~Off()
{
    cout << "OFF d-tor\n" << endl;
}

void Off::on(Component *c)
{
    c->setCurrent(new On);
    delete this;
}
