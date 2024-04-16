#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemCheckbox
     * constructor

***********************************************************************/
ach::MenuItemCheckbox::MenuItemCheckbox(ach::Menu *_menu, const char *_name) : MenuItem(_menu, _name)
{
	box = new sf::RectangleShape();

	box->setSize(sf::Vector2f(menu->spacing - 2.0f, menu->spacing - 2.0f));
	box->setOutlineThickness(1.0f);
	box->setOutlineColor(menu->text->getFillColor());
	box->setOrigin(menu->spacing + 1.0f, -1.0f);
}



/***********************************************************************
     * MenuItemCheckbox
     * destructor

***********************************************************************/
ach::MenuItemCheckbox::~MenuItemCheckbox()
{
	delete box;
}



/***********************************************************************
     * MenuItemCheckbox
     * action

***********************************************************************/
void ach::MenuItemCheckbox::action()
{
	state = !state;
}



/***********************************************************************
     * MenuItemCheckbox
     * render

***********************************************************************/
void ach::MenuItemCheckbox::render(int i)
{
	if (state)
		box->setFillColor(menu->box->getOutlineColor());
	else
		box->setFillColor(sf::Color::Transparent);

	box->setPosition(menu->pos.x + menu->padding.x + menu->width, menu->pos.y + menu->padding.y + (i + 2) * menu->spacing);
	rm->draw(box, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * MenuItemCheckbox
     * finalize

***********************************************************************/
void ach::MenuItemCheckbox::finalize()
{
	state = false;
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
