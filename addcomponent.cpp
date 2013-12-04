#include "addcomponent.h"

/*!
 * \brief AddComponent::AddComponent
 * \param r
 */
AddComponent::AddComponent(Room *r)
{
    _room = r;
}

/*!
 * \brief AddComponent::execute
 * \param s
 */
void AddComponent::execute(std::string s)
{
    _room->addComponent(s);
}
