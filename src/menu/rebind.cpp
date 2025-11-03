#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemRebind
     * constructor

***********************************************************************/
ach::MenuItemRebind::MenuItemRebind(ach::Menu *_menu, const char *_name, bool _keyboard) : MenuItem(_menu, _name)
{
	keyboard = _keyboard;
	binding  = false;
	binder   = menu->binder;
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
	binding       = true;
	menu->binding = this;

	sm->play(menu->sfxPick);
	binder->clear(keyboard);
	app->ignore();
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
		action();
	else if (menu->binding == this)
		cancel();
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

	sm->play(menu->sfxPick);

	if (act < ach::ControlAction::caCount)
		return;

	apply();

	binding       = false;
	menu->binding = NULL;
}



/***********************************************************************
     * MenuItemRebind
     * cancel

***********************************************************************/
void ach::MenuItemRebind::cancel()
{
	sm->play(menu->sfxBack);

	binder->init();

	binding       = false;
	menu->binding = NULL;
}
