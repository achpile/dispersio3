#include "meta/headers.hpp"


/***********************************************************************
     * MenuItem
     * constructor

***********************************************************************/
ach::MenuItem::MenuItem(ach::Menu *_menu, const char *_name)
{
	menu   = _menu;
	parent = NULL;

	if (_name)
		strncpy(name, _name, STR_LEN_MENU);
}



/***********************************************************************
     * MenuItem
     * destructor

***********************************************************************/
ach::MenuItem::~MenuItem()
{
}



/***********************************************************************
     * MenuItem
     * translate

***********************************************************************/
void ach::MenuItem::translate()
{
	caption = lang->getv("UI.Menu.%s", name);
}
