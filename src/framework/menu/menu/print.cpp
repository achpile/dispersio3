#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * print

***********************************************************************/
void ach::Menu::print(sf::String string, float x, int y, ach::TextAlign align)
{
	text_draw(text, string, left() + x, line(y), width, align, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * Menu
     * printItem

***********************************************************************/
void ach::Menu::printItem(sf::String string, int y)
{
	print(string, offset, y, ach::TextAlign::taLeft);
}



/***********************************************************************
     * Menu
     * printCaption

***********************************************************************/
void ach::Menu::printCaption()
{
	print(current->caption, 0.0f, -2, ach::TextAlign::taCenter);
}



/***********************************************************************
     * Menu
     * printSelector

***********************************************************************/
void ach::Menu::printSelector()
{
	print(theme->selector, 0.0f, index, ach::TextAlign::taLeft);
}
