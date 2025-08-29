#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemList
     * constructor

***********************************************************************/
ach::MenuItemList::MenuItemList(ach::Menu *_menu, const char *_name, ach::Handler _handler, json_t *_data, const char *_var, json_t *_list) : MenuItem(_menu, _name)
{
	data    = _data;
	list    = _list;
	handler = _handler;

	size_t  index;
	json_t *value;

	json_array_foreach(list, index, value)
		options.push_back(new ach::Option(value));

	strncpy(var, _var, STR_LEN_MENU);
}



/***********************************************************************
     * MenuItemList
     * destructor

***********************************************************************/
ach::MenuItemList::~MenuItemList()
{
	json_decref(list);
	list_delete(options);
}



/***********************************************************************
     * MenuItemList
     * action

***********************************************************************/
void ach::MenuItemList::action(int d)
{
	index = interval_loop(index + d, 0, options.size() - 1);

	json_object_set(data, var, options[index]->value);

	sm->play(menu->sfxPick);

	if (handler)
		handler(menu->context, NULL);
}



/***********************************************************************
     * MenuItemList
     * render

***********************************************************************/
void ach::MenuItemList::render(int i)
{
	menu->print("< " + options[index]->caption + " >", 0, i, ach::TextAlign::taRight);
}



/***********************************************************************
     * MenuItemList
     * finalize

***********************************************************************/
void ach::MenuItemList::finalize()
{
	index = 0;

	list_foreach(options)
		if (json_equal(json_object_get(data, var), options[i]->value))
			index = i;
}



/***********************************************************************
     * MenuItemList
     * translate

***********************************************************************/
void ach::MenuItemList::translate()
{
	caption = lm->getv("UI.Menu.%s", name);

	list_foreach(options)
		if (options[i]->token) options[i]->caption = lm->get (options[i]->name);
		else                   options[i]->caption = str_utf8(options[i]->name);
}



/***********************************************************************
     * MenuItemList
     * left

***********************************************************************/
void ach::MenuItemList::left()
{
	action(-1);
}



/***********************************************************************
     * MenuItemList
     * right

***********************************************************************/
void ach::MenuItemList::right()
{
	action(1);
}



/***********************************************************************
     * MenuItemList
     * click

***********************************************************************/
void ach::MenuItemList::click()
{
	action(1);
}



/***********************************************************************
     * MenuItemList
     * rclick

***********************************************************************/
void ach::MenuItemList::rclick()
{
	action(-1);
}
