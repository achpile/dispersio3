#include "meta/headers.hpp"


/***********************************************************************
     * MenuItem
     * constructor

***********************************************************************/
ach::MenuItem::MenuItem(ach::Menu *_menu, const char *_name)
{
	menu = _menu;

	strncpy(name, _name, sizeof(name));
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
