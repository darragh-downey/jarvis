#include "state.h"
#include <iostream>

using namespace std;

State::State()
{
}

State::~State()
{
}

void State::on(Component *c)
{
    cout << c->getName() << " already ON\n" << endl;
}

void State::off(Component *c)
{
    cout << c->getName() << " already OFF\n" << endl;
}
