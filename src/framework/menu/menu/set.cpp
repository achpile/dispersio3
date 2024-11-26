#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * setWidth

***********************************************************************/
void ach::Menu::setWidth(float _width)
{
	width = _width;

	calculate();
}



/***********************************************************************
     * Menu
     * setWidthE

***********************************************************************/
void ach::Menu::setWidthE(float _width)
{
	width = _width - offset - padding.x * 2;

	calculate();
}



/***********************************************************************
     * Menu
     * setHeight

***********************************************************************/
void ach::Menu::setHeight(int _lines)
{
	lines  = _lines;
	height = padding.y * 2 + (_lines + 2) * spacing;

	calculate();
}



/***********************************************************************
     * Menu
     * setHeightE

***********************************************************************/
void ach::Menu::setHeightE(float _height)
{
	lines  = floor((_height - padding.y * 2) / spacing) - 2;
	height = _height;

	calculate();
}



/***********************************************************************
     * Menu
     * setPosition

***********************************************************************/
void ach::Menu::setPosition(sf::Vector2f _pos)
{
	pos = _pos;

	calculate();
}



/***********************************************************************
     * Menu
     * setPadding

***********************************************************************/
void ach::Menu::setPadding(sf::Vector2f _padding)
{
	padding = _padding;

	calculate();
}
