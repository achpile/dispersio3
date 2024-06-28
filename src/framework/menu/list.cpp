#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemList
     * constructor

***********************************************************************/
ach::MenuItemList::MenuItemList(ach::Menu *_menu, const char *_name, ach::Handler _handler, json_t *_data, json_t *_list, bool _token) : MenuItem(_menu, _name)
{
	data    = _data;
	list    = _list;
	token   = _token;
	handler = _handler;

	const char *value;
	json_t     *caption;

	json_object_foreach(list, value, caption)
		options.push_back(ach::Option("", value));
}



/***********************************************************************
     * MenuItemList
     * destructor

***********************************************************************/
ach::MenuItemList::~MenuItemList()
{
	json_decref(list);
	options.clear();
}



/***********************************************************************
     * MenuItemList
     * action

***********************************************************************/
void ach::MenuItemList::action(int d)
{
	index = interval_loop(index + d, 0, options.size() - 1);

	json_string_set(data, options[index].value);
	sm->play(menu->sfxPick);

	if (handler)
		handler(NULL);
}



/***********************************************************************
     * MenuItemList
     * render

***********************************************************************/
void ach::MenuItemList::render(int i)
{
	menu->print("< " + options[index].caption + " >", 0, i, ach::TextAlign::taRight);
}



/***********************************************************************
     * MenuItemList
     * finalize

***********************************************************************/
void ach::MenuItemList::finalize()
{
	index = 0;

	listForeach(options)
		if (!strncmp(json_string_value(data), options[i].value, STR_LEN_MENU))
			index = i;
}



/***********************************************************************
     * MenuItemList
     * translate

***********************************************************************/
void ach::MenuItemList::translate()
{
	caption = lang->getv("UI.Menu.%s", name);

	listForeach(options)
		if (token)
			options[i].caption = lang->getv("UI.Options.%s", json_object_get_string(list, options[i].value));
		else
			options[i].caption = str_utf8(json_object_get_string(list, options[i].value));
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
