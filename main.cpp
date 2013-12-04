#include "control.h"

using namespace std;


int main()
{

    House *house = House::instance();
    Control *control = new Control(house);
    control->run();

    return 0;
}

