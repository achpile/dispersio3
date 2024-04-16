#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemCheckbox
     * constructor

***********************************************************************/
ach::MenuItemCheckbox::MenuItemCheckbox(ach::Menu *_menu, const char *_name) : MenuItem(_menu, _name)
{
	box = new sf::RectangleShape();
	fill = new sf::RectangleShape();

	box->setSize(sf::Vector2f(menu->spacing - MENU_BOX_SHRINK, menu->spacing - MENU_BOX_SHRINK));
	box->setOrigin(menu->spacing + MENU_THICKNESS - MENU_BOX_SHRINK, MENU_THICKNESS - MENU_BOX_SHRINK);
	box->setFillColor(sf::Color::Transparent);
	box->setOutlineThickness(MENU_THICKNESS);
	box->setOutlineColor(menu->text->getFillColor());

	fill->setSize(sf::Vector2f(menu->spacing - MENU_BOX_SHRINK * 1.5f, menu->spacing - MENU_BOX_SHRINK * 1.5f));
	fill->setOrigin(menu->spacing + MENU_THICKNESS - MENU_BOX_SHRINK * 1.25f, MENU_THICKNESS - MENU_BOX_SHRINK * 1.25f);
	fill->setFillColor(menu->box->getOutlineColor());
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
	state = !state;
}



/***********************************************************************
     * MenuItemCheckbox
     * render

***********************************************************************/
void ach::MenuItemCheckbox::render(int i)
{
	box->setPosition (menu->pos.x + menu->padding.x + menu->width, menu->pos.y + menu->padding.y + (i + 2) * menu->spacing);
	fill->setPosition(menu->pos.x + menu->padding.x + menu->width, menu->pos.y + menu->padding.y + (i + 2) * menu->spacing);

	rm->draw(box , ach::RenderLayer::rlGUI);

	if (state)
		rm->draw(fill, ach::RenderLayer::rlGUI);
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
