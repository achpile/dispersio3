#include "meta/headers.hpp"


/***********************************************************************
     * Text
     * constructor

***********************************************************************/
ach::Text::Text(sf::Font *font, int size)
{
	align   = ach::TextAlign::taLeft;
	layer   = ach::RenderLayer::rlGUI;
	pos     = sf::Vector2f(0.0f, 0.0f);
	spacing = MENU_SPACING;
	width   = 0.0f;
	string  = "";

	text   = new sf::Text(string, *font, size);
}



/***********************************************************************
     * Text
     * destructor

***********************************************************************/
ach::Text::~Text()
{
	delete text;

	strings.clear();
}



/***********************************************************************
     * Text
     * render

***********************************************************************/
void ach::Text::render()
{
	list_foreach(strings)
		text_draw(text, strings[i], pos.x, pos.y + spacing * i, width, align, layer);
}



/***********************************************************************
     * Text
     * setString

***********************************************************************/
void ach::Text::setString(sf::String _string)
{
	string = _string;

	calc();
}



/***********************************************************************
     * Text
     * setPosition

***********************************************************************/
void ach::Text::setPosition(sf::Vector2f _pos)
{
	pos = _pos;
}



/***********************************************************************
     * Text
     * setWidth

***********************************************************************/
void ach::Text::setWidth(float _width)
{
	width = _width;

	calc();
}



/***********************************************************************
     * Text
     * setFont

***********************************************************************/
void ach::Text::setFont(sf::Font *font)
{
	text->setFont(*font);

	calc();
}



/***********************************************************************
     * Text
     * setSize

***********************************************************************/
void ach::Text::setSize(int size)
{
	text->setCharacterSize(size);

	calc();
}



/***********************************************************************
     * Text
     * setColor

***********************************************************************/
void ach::Text::setColor(sf::Color color)
{
	text->setFillColor(color);
}



/***********************************************************************
     * Text
     * setSpacing

***********************************************************************/
void ach::Text::setSpacing(int _spacing)
{
	spacing = _spacing + MENU_SPACING;
}



/***********************************************************************
     * Text
     * setAlign

***********************************************************************/
void ach::Text::setAlign(ach::TextAlign _align)
{
	align = _align;
}



/***********************************************************************
     * Text
     * setLayer

***********************************************************************/
void ach::Text::setLayer(ach::RenderLayer _layer)
{
	layer = _layer;
}



/***********************************************************************
     * Text
     * calc

***********************************************************************/
void ach::Text::calc()
{
	strings.clear();

	strings.push_back(string);
}
