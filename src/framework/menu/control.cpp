#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemControl
     * constructor

***********************************************************************/
ach::MenuItemControl::MenuItemControl(ach::Menu *_menu, ach::ControlAction _action) : MenuItem(_menu, NULL)
{
	action = _action;
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
     * translate

***********************************************************************/
void ach::MenuItemControl::translate()
{
	caption = lang->getv("UI.Action.%s", pair_get_string(action, pairAction));
}



/***********************************************************************
     * MenuItemControl
     * render

***********************************************************************/
void ach::MenuItemControl::render(int i)
{
	menu->print(ctrl->keys[action].getKey(), 0, i, ach::TextAlign::taRight);
}
