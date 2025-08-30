#include "meta/headers.hpp"


/***********************************************************************
     * Message
     * constructor

***********************************************************************/
ach::Message::Message()
{
	text = new ach::Text(theme->menu.font, theme->menu.size);
	box  = new ach::RectangleShape();

	style();
}



/***********************************************************************
     * Message
     * destructor

***********************************************************************/
ach::Message::~Message()
{
}



/***********************************************************************
     * Message
     * render

***********************************************************************/
void ach::Message::render()
{
}



/***********************************************************************
     * Message
     * style

***********************************************************************/
void ach::Message::style()
{
	text->setFont(theme->menu.font);
	text->setColor(theme->menu.color);

	box->setFillColor(theme->menu.bg);
	box->setOutlineColor(theme->menu.border);
	box->setRound(theme->menu.round);
}
