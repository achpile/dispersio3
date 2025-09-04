#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * left

***********************************************************************/
float ach::Menu::left()
{
	return pos.x + padding.x;
}



/***********************************************************************
     * Menu
     * right

***********************************************************************/
float ach::Menu::right()
{
	return left() + width;
}



/***********************************************************************
     * Menu
     * top

***********************************************************************/
float ach::Menu::top()
{
	return pos.y + padding.y;
}



/***********************************************************************
     * Menu
     * line

***********************************************************************/
float ach::Menu::line(int l)
{
	return top() + spacing * (l + 2);
}



/***********************************************************************
     * Menu
     * calculate

***********************************************************************/
void ach::Menu::calculate()
{
	spacing = theme->text->spacing() + MENU_SPACING;
	offset  = spacing;

	text->setCharacterSize(theme->text->size);

	box->setPosition(pos);
	box->setSize(sf::Vector2f(padding.x * 2 + offset + width, height));
}
