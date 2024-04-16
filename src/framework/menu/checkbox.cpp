#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemCheckbox
     * constructor

***********************************************************************/
ach::MenuItemCheckbox::MenuItemCheckbox(ach::Menu *_menu, const char *_name, json_t *_data, const char *_var) : MenuItem(_menu, _name)
{
	data = _data;

	box  = new sf::RectangleShape();
	fill = new sf::RectangleShape();

	box->setSize(sf::Vector2f(menu->size, menu->size));
	box->setOrigin(menu->size, 0);
	box->setFillColor(sf::Color::Transparent);
	box->setOutlineThickness(MENU_THICKNESS);
	box->setOutlineColor(menu->text->getFillColor());

	fill->setSize(sf::Vector2f(menu->size - MENU_BOX_SHRINK, menu->size - MENU_BOX_SHRINK));
	fill->setOrigin(menu->size - MENU_BOX_SHRINK / 2, - MENU_BOX_SHRINK / 2);
	fill->setFillColor(menu->box->getOutlineColor());

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
     * action

***********************************************************************/
void ach::MenuItemCheckbox::action()
{
	value = !value;

	json_object_set_boolean(data, var, value);
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
