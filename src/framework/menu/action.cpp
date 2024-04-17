#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemAction
     * constructor

***********************************************************************/
ach::MenuItemAction::MenuItemAction(ach::Menu *_menu, const char *_name, ach::Handler _handler, json_t *_param) : MenuItem(_menu, _name)
{
	param   = _param;
	handler = _handler;
}



/***********************************************************************
     * MenuItemAction
     * destructor

***********************************************************************/
ach::MenuItemAction::~MenuItemAction()
{
	if (param)
		json_decref(param);
}



/***********************************************************************
     * MenuItemAction
     * action

***********************************************************************/
void ach::MenuItemAction::action()
{
	if (handler)
		handler(param);
}



/***********************************************************************
     * MenuItemAction
     * pick

***********************************************************************/
void ach::MenuItemAction::pick()
{
	action();
}



/***********************************************************************
     * MenuItemAction
     * click

***********************************************************************/
void ach::MenuItemAction::click()
{
	action();
}
