#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemRebind
     * constructor

***********************************************************************/
ach::MenuItemRebind::MenuItemRebind(ach::Menu *_menu, const char *_name, bool _keyboard) : MenuItem(_menu, _name)
{
	keyboard  = _keyboard;
	isBinding = false;
}



/***********************************************************************
     * MenuItemRebind
     * destructor

***********************************************************************/
ach::MenuItemRebind::~MenuItemRebind()
{
}



/***********************************************************************
     * MenuItemRebind
     * action

***********************************************************************/
void ach::MenuItemRebind::action()
{
	menu->binding = this;
	isBinding     = true;
}



/***********************************************************************
     * MenuItemRebind
     * pick

***********************************************************************/
void ach::MenuItemRebind::pick()
{
	if (!menu->binding)
		action();
}



/***********************************************************************
     * MenuItemRebind
     * click

***********************************************************************/
void ach::MenuItemRebind::click()
{
	if (!menu->binding)
	{
		action();
	}
	else if (menu->binding == this)
	{
		isBinding = false;
		menu->binding = NULL;
	}
}



/***********************************************************************
     * MenuItemRebind
     * bind

***********************************************************************/
void ach::MenuItemRebind::bind(sf::Keyboard::Key code)
{
	if (!keyboard)
		return;

	if (code == sf::Keyboard::Unknown)
		return;
/*
	if (ctrl->bind(act, code))
	{
		isBinding = false;
		menu->binding = NULL;
	}
*/
}



/***********************************************************************
     * MenuItemRebind
     * bind

***********************************************************************/
void ach::MenuItemRebind::bind(ach::JoystickCode code)
{
	if (keyboard)
		return;

	if (code == ach::JoystickCode::jcUnknown)
		return;
/*
	if (ctrl->bind(act, code))
	{
		isBinding = false;
		menu->binding = NULL;
	}
*/
}
