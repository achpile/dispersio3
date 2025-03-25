#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemRebind
     * constructor

***********************************************************************/
ach::MenuItemRebind::MenuItemRebind(ach::Menu *_menu, const char *_name, bool _keyboard) : MenuItem(_menu, _name)
{
	keyboard  = _keyboard;
	isBinding = false;
	binder    = menu->binder;
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
	act           = 0;
	menu->binding = this;
	isBinding     = true;

	binder->clear(keyboard);
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
		binder->init();

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
	if (assign((ach::ControlAction)act, code))
		next();
}



/***********************************************************************
     * MenuItemRebind
     * bind

***********************************************************************/
void ach::MenuItemRebind::bind(ach::JoystickCode code)
{
	if (assign((ach::ControlAction)act, code))
		next();
}



/***********************************************************************
     * MenuItemRebind
     * next

***********************************************************************/
void ach::MenuItemRebind::next()
{
	act++;

	if (act < ach::ControlAction::caCount)
		return;

	apply();

	isBinding = false;
	menu->binding = NULL;
}
