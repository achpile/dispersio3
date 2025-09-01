#include "meta/headers.hpp"


/***********************************************************************
     * Status
     * constructor

***********************************************************************/
ach::Status::Status()
{
	width = 500.0f;
	box   = new ach::RectangleShape();
	text  = new sf::Text();

	box->setPosition(sf::Vector2f(150.0f, 20.0f));
	box->setOutlineThickness(MENU_THICKNESS);

	style();
}



/***********************************************************************
     * Status
     * destructor

***********************************************************************/
ach::Status::~Status()
{
	list_delete(lines);

	delete text;
	delete box;
}



/***********************************************************************
     * Status
     * update

***********************************************************************/
void ach::Status::update()
{
	list_delete(lines);
}



/***********************************************************************
     * Status
     * render

***********************************************************************/
void ach::Status::render()
{
	rm->draw(box, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * Status
     * style

***********************************************************************/
void ach::Status::style()
{
	spacing = theme->menu.spacing + MENU_SPACING;

	box->style(&theme->menu);
	box->setSize(sf::Vector2f(width, 240.0f));

	text->setCharacterSize(theme->menu.size);
	text->setFont(*theme->menu.font);
	text->setFillColor(theme->menu.color);
}



/***********************************************************************
     * Status
     * translate

***********************************************************************/
void ach::Status::translate()
{
	update();
}
