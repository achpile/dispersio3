#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemCheckbox
     * constructor

***********************************************************************/
ach::MenuItemCheckbox::MenuItemCheckbox(ach::Menu *_menu, const char *_name, ach::Handler _handler, json_t *_data, const char *_var) : MenuItem(_menu, _name)
{
	data    = _data;
	handler = _handler;

	box  = new sf::RectangleShape();
	fill = new sf::RectangleShape();

	box->setFillColor(sf::Color::Transparent);
	box->setOutlineThickness(MENU_THICKNESS);

	style();

	strncpy(var, _var, STR_LEN_MENU);
}



/***********************************************************************
     * MenuItemCheckbox
     * destructor

***********************************************************************/
ach::MenuItemCheckbox::~MenuItemCheckbox()
{
	delete box;
	delete fill;
}



/***********************************************************************
     * MenuItemCheckbox
     * style

***********************************************************************/
void ach::MenuItemCheckbox::style()
{
	box->setSize(sf::Vector2f(menu->theme->text->spacing(), menu->theme->text->spacing()));
	box->setOrigin(menu->theme->text->spacing(), 0);
	box->setOutlineColor(menu->theme->text->color);

	fill->setSize(sf::Vector2f(menu->theme->text->spacing() - MENU_BOX_SHRINK, menu->theme->text->spacing() - MENU_BOX_SHRINK));
	fill->setOrigin(menu->theme->text->spacing() - MENU_BOX_SHRINK / 2, - MENU_BOX_SHRINK / 2);
	fill->setFillColor(menu->theme->box->border);
}



/***********************************************************************
     * MenuItemCheckbox
     * action

***********************************************************************/
void ach::MenuItemCheckbox::action()
{
	value = !value;

	json_object_set_boolean(data, var, value);
	sm->play(menu->sfxPick);

	if (handler)
		handler(menu->context, NULL);
}



/***********************************************************************
     * MenuItemCheckbox
     * render

***********************************************************************/
void ach::MenuItemCheckbox::render(int i)
{
	box->setPosition (menu->right(), menu->line(i));
	fill->setPosition(menu->right(), menu->line(i));

	rm->draw(box , ach::RenderLayer::rlGUI);

	if (value)
		rm->draw(fill, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * MenuItemCheckbox
     * finalize

***********************************************************************/
void ach::MenuItemCheckbox::finalize()
{
	value = json_object_get_boolean(data, var);
}



/***********************************************************************
     * MenuItemCheckbox
     * pick

***********************************************************************/
void ach::MenuItemCheckbox::pick()
{
	action();
}



/***********************************************************************
     * MenuItemCheckbox
     * click

***********************************************************************/
void ach::MenuItemCheckbox::click()
{
	action();
}



/***********************************************************************
     * MenuItemCheckbox
     * rclick

***********************************************************************/
void ach::MenuItemCheckbox::rclick()
{
	action();
}
