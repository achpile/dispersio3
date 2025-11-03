#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemReset
     * constructor

***********************************************************************/
ach::MenuItemReset::MenuItemReset(ach::Menu *_menu, const char *_name, bool _keyboard) : MenuItem(_menu, _name)
{
	keyboard = _keyboard;
}



/***********************************************************************
     * MenuItemReset
     * destructor

***********************************************************************/
ach::MenuItemReset::~MenuItemReset()
{
}



/***********************************************************************
     * MenuItemReset
     * action

***********************************************************************/
void ach::MenuItemReset::action()
{
	json_t     *act;
	const char *i;

	json_object_foreach(json_object_get(settings->data, "Control"), i, act)
		json_object_del(act, keyboard ? "Key" : "Joy");

	json_dm_generate_default(settings->data, json_object_get(dm->dm, "Settings"));

	ctrl->init();
	ctrl->reset();

	sm->play(menu->sfxPick);
	menu->binder->init();
}



/***********************************************************************
     * MenuItemReset
     * pick

***********************************************************************/
void ach::MenuItemReset::pick()
{
	action();
}



/***********************************************************************
     * MenuItemReset
     * click

***********************************************************************/
void ach::MenuItemReset::click()
{
	action();
}
