#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemControl
     * constructor

***********************************************************************/
ach::MenuItemControl::MenuItemControl(ach::Menu *_menu, ach::ControlAction _act, bool _keyboard) : MenuItem(_menu, NULL)
{
	act      = _act;
	keyboard = _keyboard;
	binding  = false;
	binder   = menu->binder;
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
	binding       = true;
	menu->binding = this;

	binder->keys[act].clear(keyboard);
}



/***********************************************************************
     * MenuItemControl
     * render

***********************************************************************/
void ach::MenuItemControl::render(int i)
{
	if (keyboard) menu->print(pair_get_string(binder->keys[act].key, pairKey), 0, i, ach::TextAlign::taRight);
	else          menu->print(pair_get_string(binder->keys[act].joy, pairJoy), 0, i, ach::TextAlign::taRight);
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
		action();
	else if (menu->binding == this)
		cancel();
}



/***********************************************************************
     * MenuItemControl
     * bind

***********************************************************************/
void ach::MenuItemControl::bind(sf::Keyboard::Key code)
{
	if (assign(act, code))
		finish();
}



/***********************************************************************
     * MenuItemControl
     * bind

***********************************************************************/
void ach::MenuItemControl::bind(ach::JoystickCode code)
{
	if (assign(act, code))
		finish();
}



/***********************************************************************
     * MenuItemControl
     * finish

***********************************************************************/
void ach::MenuItemControl::finish()
{
	sm->play(menu->sfxPick);

	apply();

	binding       = false;
	menu->binding = NULL;
}



/***********************************************************************
     * MenuItemControl
     * cancel

***********************************************************************/
void ach::MenuItemControl::cancel()
{
	sm->play(menu->sfxBack);

	binder->init();

	binding       = false;
	menu->binding = NULL;
}
