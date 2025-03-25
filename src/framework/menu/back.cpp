#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemBack
     * constructor

***********************************************************************/
ach::MenuItemBack::MenuItemBack(ach::Menu *_menu, const char *_name) : MenuItem(_menu, _name)
{
}



/***********************************************************************
     * MenuItemBack
     * destructor

***********************************************************************/
ach::MenuItemBack::~MenuItemBack()
{
}



/***********************************************************************
     * MenuItemBack
     * action

***********************************************************************/
void ach::MenuItemBack::action()
{
	if (menu->binding)
	{
		menu->binding->binding = false;
		menu->binding          = NULL;
	}

	if (parent->parent)
	{
		menu->go(parent->parent, parent);
		sm->play(menu->sfxBack);
	}
}



/***********************************************************************
     * MenuItemBack
     * pick

***********************************************************************/
void ach::MenuItemBack::pick()
{
	action();
}



/***********************************************************************
     * MenuItemBack
     * click

***********************************************************************/
void ach::MenuItemBack::click()
{
	action();
}
