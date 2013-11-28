#include <iostream>
#include "component.h"
#include "device.h"
#include "light.h"
#include "factory.h"
#include "roomfactory.h"
#include "appliancefactory.h"
#include "devicefactory.h"

using namespace std;

int main()
{
    Factory *factory;
    Factory *dFactory;
    RoomFactory *roomFactory = new RoomFactory;
    factory = new ApplianceFactory;
    dFactory = new DeviceFactory;
    Component *dishwasher = factory->create("Dishwasher");
    Component *washingmachine = factory->create("Washingmachine");
    Component *tv = dFactory->create("tv");
    Room *livingRoom = roomFactory->create("Living Room");
    Room *kitchen = roomFactory->create("Kitchen");
    kitchen->addComponent(dishwasher);
    kitchen->addComponent(washingmachine);
    livingRoom->addComponent(tv);
    kitchen->turnOnComponent("Dishwasher");
    kitchen->turnOnComponent("Washingmachine");
    livingRoom->turnOnComponent("tv");
    livingRoom->turnOnComponent("tv");
    livingRoom->turnOffComponent();
    return 0;
}

