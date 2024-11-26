#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * init

***********************************************************************/
void ach::Menu::init(const char *_root)
{
	root    = new ach::MenuItemFolder(this, _root);
	current = root;
	enabled = true;

	items.push_back(root);
}



/***********************************************************************
     * Menu
     * add

***********************************************************************/
void ach::Menu::add(const char *_parent, ach::MenuItem *item)
{
	items.push_back(item);

	ach::MenuItem *parent = NULL;

	list_foreach(items)
		if (!strncmp(_parent, items[i]->name, STR_LEN_MENU))
		{
			parent = items[i];
			break;
		}

	if (parent)
		parent->add(item);
}



/***********************************************************************
     * Menu
     * go

***********************************************************************/
void ach::Menu::go(ach::MenuItemFolder *parent, ach::MenuItem *item)
{
	current = parent;
	index   = 0;

	if (!item)
		return;

	list_foreach(current->items)
		if (current->items[i] == item)
			index = i;
}



/***********************************************************************
     * Menu
     * clear

***********************************************************************/
void ach::Menu::clear()
{
	root    = NULL;
	current = NULL;
	index   = 0;

	list_delete(items);
}



/***********************************************************************
     * Menu
     * reset

***********************************************************************/
void ach::Menu::reset()
{
	current = root;
	index   = 0;
}



/***********************************************************************
     * Menu
     * finalize

***********************************************************************/
void ach::Menu::finalize()
{
	list_foreach(items)
		items[i]->finalize();

	translate();
}
