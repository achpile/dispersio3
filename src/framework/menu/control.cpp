#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemControl
     * constructor

***********************************************************************/
ach::MenuItemControl::MenuItemControl(ach::Menu *_menu, ach::ControlAction _act, bool _keyboard) : MenuItem(_menu, NULL)
{
	act       = _act;
	keyboard  = _keyboard;
	isBinding = false;
}



/***********************************************************************
     * MenuItemControl
     * destructor

***********************************************************************/
ach::MenuItemControl::~MenuItemControl()
{
}



/***********************************************************************
     * MenuItemControl
     * action

***********************************************************************/
void ach::MenuItemControl::action()
{
	menu->binding = this;
	isBinding     = true;
}



/***********************************************************************
     * MenuItemControl
     * render

***********************************************************************/
void ach::MenuItemControl::render(int i)
{
	if (isBinding)
		menu->print("...", 0, i, ach::TextAlign::taRight);
	else
	{
		if (keyboard) menu->print(pair_get_string(ctrl->keys[act].key, pairKey), 0, i, ach::TextAlign::taRight);
		else          menu->print(pair_get_string(ctrl->keys[act].joy, pairJoy), 0, i, ach::TextAlign::taRight);
	}
}



/***********************************************************************
     * MenuItemControl
     * translate

***********************************************************************/
void ach::MenuItemControl::translate()
{
	caption = lm->getv("UI.Control.%s", pair_get_string(act, pairAction));
}



/***********************************************************************
     * MenuItemControl
     * pick

***********************************************************************/
void ach::MenuItemControl::pick()
{
	if (!menu->binding)
		action();
}



/***********************************************************************
     * MenuItemControl
     * click

***********************************************************************/
void ach::MenuItemControl::click()
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
     * MenuItemControl
     * bind

***********************************************************************/
void ach::MenuItemControl::bind(sf::Keyboard::Key code)
{
	if (ctrl->bind(act, code))
	{
		isBinding = false;
		menu->binding = NULL;
	}
}
