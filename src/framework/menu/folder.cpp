#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemFolder
     * constructor

***********************************************************************/
ach::MenuItemFolder::MenuItemFolder(ach::Menu *_menu, const char *_name) : MenuItem(_menu, _name)
{
}



/***********************************************************************
     * MenuItemFolder
     * destructor

***********************************************************************/
ach::MenuItemFolder::~MenuItemFolder()
{
}



/***********************************************************************
     * MenuItemFolder
     * add

***********************************************************************/
void ach::MenuItemFolder::add(ach::MenuItem *item)
{
	item->parent = this;

	items.push_back(item);
}



/***********************************************************************
     * MenuItemFolder
     * finalize

***********************************************************************/
void ach::MenuItemFolder::finalize()
{
	ach::MenuItemBack *back = new ach::MenuItemBack(menu, parent ? "Back" : "Exit");

	menu->items.push_back(back);
	add(back);
}



/***********************************************************************
     * MenuItemFolder
     * action

***********************************************************************/
void ach::MenuItemFolder::action()
{
	menu->go(this, NULL);
}



/***********************************************************************
     * MenuItemFolder
     * pick

***********************************************************************/
void ach::MenuItemFolder::pick()
{
	action();
}



/***********************************************************************
     * MenuItemFolder
     * click

***********************************************************************/
void ach::MenuItemFolder::click()
{
	action();
}
