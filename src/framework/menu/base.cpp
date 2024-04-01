#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * constructor

***********************************************************************/
ach::Menu::Menu()
{
	box     = new sf::RectangleShape();
	text    = new sf::Text();
	root    = new ach::MenuItem();
	current = root;

	height  = 8;
	size    = 12;
	padding = sf::Vector2f(10.0f, 10.0f);

	text->setFont(*resources->fonts.base);

	box->setFillColor(sf::Color::Black);
	box->setOutlineColor(sf::Color::Green);
	box->setOutlineThickness(1.0f);

	calculate();
}



/***********************************************************************
     * Menu
     * destructor

***********************************************************************/
ach::Menu::~Menu()
{
	delete root;
	delete text;
	delete box;
}



/***********************************************************************
     * Menu
     * update

***********************************************************************/
void ach::Menu::update()
{
	render();
}



/***********************************************************************
     * Menu
     * render

***********************************************************************/
void ach::Menu::render()
{
	app->rm->draw(box, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * Menu
     * calculate

***********************************************************************/
void ach::Menu::calculate()
{
	spacing = text->getFont()->getLineSpacing(size);

	box->setPosition(pos);
	box->setSize(sf::Vector2f(padding.x * 2 + width, padding.y * 2.0f + height * spacing));
}



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
     * setHeight

***********************************************************************/
void ach::Menu::setHeight(int _height)
{
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



/***********************************************************************
     * Menu
     * setFontSize

***********************************************************************/
void ach::Menu::setFontSize(int _size)
{
	size = _size;

	calculate();
}
