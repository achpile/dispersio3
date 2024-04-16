#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * constructor

***********************************************************************/
ach::Menu::Menu(const char *name)
{
	box      = new sf::RectangleShape();
	text     = new sf::Text();
	root     = new ach::MenuItemFolder(this, name);
	current  = root;

	index    = 0;
	width    = 0;
	height   = 0;
	size     = 16;
	isActive = true;
	padding  = sf::Vector2f(MENU_PADDING, MENU_PADDING);

	text->setFont(*resources->fonts.base);
	text->setFillColor(sf::Color::White);

	box->setFillColor(sf::Color::Black);
	box->setOutlineColor(sf::Color::Green);
	box->setOutlineThickness(MENU_THICKNESS);

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
		current->items[i]->render(i);
	}

	printCaption();
	printSelector();
}



/***********************************************************************
     * Menu
     * controls

***********************************************************************/
void ach::Menu::controls()
{
	if (ctrl->keys[caUp    ].pressed) index--;
	if (ctrl->keys[caDown  ].pressed) index++;

	index %= current->items.size();

	if (ctrl->keys[caLeft  ].pressed) current->items[index]->left();
	if (ctrl->keys[caRight ].pressed) current->items[index]->right();
	if (ctrl->keys[caAction].pressed) current->items[index]->pick();

	if (ctrl->keys[caMenu  ].pressed) current->items.back()->pick();
}



/***********************************************************************
     * Menu
     * add

***********************************************************************/
void ach::Menu::add(const char *_parent, ach::MenuItem *item)
{
	items.push_back(item);

	ach::MenuItem *parent = NULL;

	for (unsigned int i = 0; i < items.size(); i++)
		if (!strncmp(_parent, items[i]->name, STR_LEN_MENU))
		{
			parent = items[i];
			break;
		}

	if (parent)
		parent->add(item);
}



/***********************************************************************
     * Menu
     * go

***********************************************************************/
void ach::Menu::go(ach::MenuItemFolder *parent, ach::MenuItem *item)
{
	current = parent;
	index   = 0;

	if (!item)
		return;

	for (unsigned int i = 0; i < current->items.size(); i++)
		if (current->items[i] == item)
			index = i;
}



/***********************************************************************
     * Menu
     * inside

***********************************************************************/
bool ach::Menu::inside(sf::Vector2f v)
{
	return sf::FloatRect(pos.x, line(0), width, current->items.size() * spacing).contains(v);
}



/***********************************************************************
     * Menu
     * hover

***********************************************************************/
void ach::Menu::hover(sf::Vector2f v)
{
	if (!inside(v))
		return;

	index = floor((v.y - line(0)) / spacing);
}



/***********************************************************************
     * Menu
     * click

***********************************************************************/
void ach::Menu::click(sf::Vector2f v, bool left)
{
	if (!inside(v))
		return;

	hover(pos);

	if (left)
		current->items[index]->click();
	else
		current->items[index]->rclick();
}



/***********************************************************************
     * Menu
     * reset

***********************************************************************/
void ach::Menu::reset()
{
	current = root;
	index   = 0;
}



/***********************************************************************
     * Menu
     * finalize

***********************************************************************/
void ach::Menu::finalize()
{
	for (unsigned int i = 0; i < items.size(); i++)
		items[i]->finalize();

	translate();
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
	offset  = spacing;

	text->setCharacterSize(size);

	box->setPosition(pos);
	box->setSize(sf::Vector2f(padding.x * 2 + offset + width, padding.y * 2 + (height + 2) * spacing));
}



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
	textDraw(text, string, left() + x, line(y), width, align, ach::RenderLayer::rlGUI);
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
	print(">", 0.0f, index, ach::TextAlign::taLeft);
}
