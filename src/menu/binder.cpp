#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemBinder
     * assign

***********************************************************************/
bool ach::MenuItemBinder::assign(ach::ControlAction act, sf::Keyboard::Key code)
{
	if (!keyboard)
		return false;

	if (code == sf::Keyboard::Unknown)
		return false;

	return binder->bind(act, code);
}



/***********************************************************************
     * MenuItemBinder
     * assign

***********************************************************************/
bool ach::MenuItemBinder::assign(ach::ControlAction act, ach::JoystickCode code)
{
	if (keyboard)
		return false;

	if (code == ach::JoystickCode::jcUnknown)
		return false;

	return binder->bind(act, code);
}



/***********************************************************************
     * MenuItemBinder
     * apply

***********************************************************************/
void ach::MenuItemBinder::apply()
{
	binder->dump();
	ctrl->init();
	ctrl->reset();
}
