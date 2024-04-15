#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * constructor

***********************************************************************/
ach::Menu::Menu()
{
	box     = new sf::RectangleShape();
	text    = new sf::Text();
	root    = new ach::MenuItemFolder(this, "Main");
	current = root;

	index   = 0;
	width   = 0;
	height  = 0;
	size    = 16;
	offset  = 20;
	padding = sf::Vector2f(10.0f, 10.0f);

	text->setFont(*resources->fonts.base);
	text->setFillColor(sf::Color::White);

	box->setFillColor(sf::Color::Black);
	box->setOutlineColor(sf::Color::Green);
	box->setOutlineThickness(1.0f);

	items.push_back(root);

	calculate();
}



/***********************************************************************
     * Menu
     * destructor

***********************************************************************/
ach::Menu::~Menu()
{
	delete text;
	delete box;

	listDelete(items);
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
	rm->draw(box, ach::RenderLayer::rlGUI);

	for (unsigned int i = 0; i < current->items.size(); i++)
	{
		printItem(current->items[i]->caption, i);
	}

	printCaption();
	printSelector();
}



/***********************************************************************
     * Menu
     * translate

***********************************************************************/
void ach::Menu::translate()
{
	for (unsigned int i = 0; i < items.size(); i++)
		items[i]->translate();
}



/***********************************************************************
     * Menu
     * calculate

***********************************************************************/
void ach::Menu::calculate()
{
	spacing = text->getFont()->getLineSpacing(size);

	text->setCharacterSize(size);

	box->setPosition(pos);
	box->setSize(sf::Vector2f(padding.x * 2 + offset + width, padding.y * 2.0f + (height + 2) * spacing));
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



/***********************************************************************
     * Menu
     * print

***********************************************************************/
void ach::Menu::print(sf::String string, float x, int y, ach::TextAlign align)
{
	textDraw(text, string, pos.x + padding.x + x, pos.y + padding.y + y * spacing, width, align, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * Menu
     * printItem

***********************************************************************/
void ach::Menu::printItem(sf::String string, int y)
{
	print(string, offset, y + 2, ach::TextAlign::taLeft);
}



/***********************************************************************
     * Menu
     * printCaption

***********************************************************************/
void ach::Menu::printCaption()
{
	print(current->caption, 0.0f, 0, ach::TextAlign::taCenter);
}



/***********************************************************************
     * Menu
     * printSelector

***********************************************************************/
void ach::Menu::printSelector()
{
	print(">", 0.0f, index + 2, ach::TextAlign::taLeft);
}
