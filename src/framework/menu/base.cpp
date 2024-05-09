#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * constructor

***********************************************************************/
ach::Menu::Menu(const char *name, sf::Font *font)
{
	box      = new sf::RectangleShape();
	text     = new sf::Text();
	root     = new ach::MenuItemFolder(this, name);
	current  = root;
	binding  = NULL;

	sfxBlip  = NULL;
	sfxBack  = NULL;
	sfxPick  = NULL;

	index    = 0;
	width    = 0;
	height   = 0;
	size     = 16;
	isActive = true;
	padding  = sf::Vector2f(MENU_PADDING, MENU_PADDING);

	text->setFont(*font);
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
     * event

***********************************************************************/
void ach::Menu::event(sf::Event e)
{
	switch (e.type)
	{
		case sf::Event::MouseMoved:
			hover(rm->transform(sf::Vector2f(e.mouseMove.x, e.mouseMove.y), ach::RenderLayer::rlGUI));
			break;


		case sf::Event::MouseButtonReleased:
			if ((e.mouseButton.button != sf::Mouse::Button::Left) && (e.mouseButton.button != sf::Mouse::Button::Right))
				break;

			click(rm->transform(sf::Vector2f(e.mouseButton.x, e.mouseButton.y), ach::RenderLayer::rlGUI), e.mouseButton.button == sf::Mouse::Button::Left);
			break;

		case sf::Event::KeyPressed:
			if (binding)
				binding->bind(e.key.code);

			break;


		default:
			break;
	}
}



/***********************************************************************
     * Menu
     * controls

***********************************************************************/
void ach::Menu::controls()
{
	if (binding)
		return;

	if (ctrl->keys[ach::ControlAction::caUp   ].pressed) move(-1);
	if (ctrl->keys[ach::ControlAction::caDown ].pressed) move( 1);

	if (ctrl->keys[ach::ControlAction::caLeft ].pressed) current->items[index]->left();
	if (ctrl->keys[ach::ControlAction::caRight].pressed) current->items[index]->right();
	if (ctrl->keys[ach::ControlAction::caJump ].pressed) current->items[index]->pick();

	if (ctrl->keys[ach::ControlAction::caMenu ].pressed) current->items.back()->pick();
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

	select(floor((v.y - line(0)) / spacing));
}



/***********************************************************************
     * Menu
     * click

***********************************************************************/
void ach::Menu::click(sf::Vector2f v, bool left)
{
	if (!inside(v))
		return;

	hover(v);

	if (left)
		current->items[index]->click();
	else
		current->items[index]->rclick();
}



/***********************************************************************
     * Menu
     * select

***********************************************************************/
void ach::Menu::select(int i)
{
	if (binding && current->items[i] != binding && i != (int)current->items.size() - 1)
		return;

	if (index != i)
	{
		index = i;
		sm->play(sfxBlip);
	}
}



/***********************************************************************
     * Menu
     * move

***********************************************************************/
void ach::Menu::move(int d)
{
	select(interval_loop(index + d, 0, current->items.size() - 1));
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
	spacing = text->getFont()->getLineSpacing(size) + MENU_SPACING;
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
     * setSound

***********************************************************************/
void ach::Menu::setSound(sf::SoundBuffer *_blip, sf::SoundBuffer *_back, sf::SoundBuffer *_pick)
{
	sfxBlip = _blip;
	sfxBack = _back;
	sfxPick = _pick;
}



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
	print(">", 0.0f, index, ach::TextAlign::taLeft);
}
