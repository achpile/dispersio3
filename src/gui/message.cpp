#include "meta/headers.hpp"


/***********************************************************************
     * Message
     * constructor

***********************************************************************/
ach::Message::Message(float _width)
{
	text = new ach::Text(&theme->menu);
	box  = new ach::RectangleShape();

	box->setOutlineThickness(MENU_THICKNESS);

	style();

	setWidth(_width);
}



/***********************************************************************
     * Message
     * destructor

***********************************************************************/
ach::Message::~Message()
{
	delete text;
	delete box;
}



/***********************************************************************
     * Message
     * update

***********************************************************************/
void ach::Message::update()
{
	box->setSize(sf::Vector2f(width, text->height() + spacing * 2));
}



/***********************************************************************
     * Message
     * render

***********************************************************************/
void ach::Message::render()
{
	rm->draw(box, ach::RenderLayer::rlGUI);

	text->render();
}



/***********************************************************************
     * Message
     * style

***********************************************************************/
void ach::Message::style()
{
	spacing = theme->menu.spacing + MENU_SPACING;

	text->style(&theme->menu);
	box->style(&theme->menu);
}



/***********************************************************************
     * Message
     * setString

***********************************************************************/
void ach::Message::setString(sf::String string)
{
	text->setString(string);

	update();
}



/***********************************************************************
     * Message
     * setPosition

***********************************************************************/
void ach::Message::setPosition(sf::Vector2f pos)
{
	box->setPosition(pos);
	text->setPosition(pos + sf::Vector2f(spacing, spacing));
}



/***********************************************************************
     * Message
     * setWidth

***********************************************************************/
void ach::Message::setWidth(float _width)
{
	width = _width;

	text->setWidth(width - spacing * 2.0f);

	update();
}
