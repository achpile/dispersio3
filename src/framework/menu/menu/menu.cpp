#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * constructor

***********************************************************************/
ach::Menu::Menu(void *_context, ach::MenuTheme *_theme)
{
	box      = new sf::RectangleShape();
	text     = new sf::Text();
	binding  = NULL;

	index    = 0;
	lines    = 0;
	width    = 0;
	height   = 0;
	enabled  = false;
	context  = _context;
	padding  = sf::Vector2f(MENU_PADDING, MENU_PADDING);

	box->setOutlineThickness(MENU_THICKNESS);

	style(_theme);
}



/***********************************************************************
     * Menu
     * destructor

***********************************************************************/
ach::Menu::~Menu()
{
	delete text;
	delete box;

	clear();
}



/***********************************************************************
     * Menu
     * update

***********************************************************************/
void ach::Menu::update()
{
}



/***********************************************************************
     * Menu
     * render

***********************************************************************/
void ach::Menu::render()
{
	rm->draw(box, ach::RenderLayer::rlGUI);

	if (!enabled)
		return;

	list_foreach(current->items)
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
	if (!enabled)
		return;


	switch (e.type)
	{
		case sf::Event::MouseMoved:
			hover(rm->transform(ach::RenderLayer::rlGUI, sf::Vector2f(e.mouseMove.x, e.mouseMove.y)));
			break;


		case sf::Event::MouseButtonReleased:
			if ((e.mouseButton.button != sf::Mouse::Button::Left) && (e.mouseButton.button != sf::Mouse::Button::Right))
				break;

			click(rm->transform(ach::RenderLayer::rlGUI, sf::Vector2f(e.mouseButton.x, e.mouseButton.y)), e.mouseButton.button == sf::Mouse::Button::Left);
			break;


		case sf::Event::KeyPressed:
			if (binding)
				binding->bind(e.key.code);

			break;


		case sf::Event::JoystickButtonPressed:
			if (binding)
				binding->bind(joystick->action(e.joystickButton.button));

			break;


		case sf::Event::JoystickMoved:
			if (binding)
				binding->bind(joystick->action(e.joystickMove.axis, e.joystickMove.position));

			break;


		default:
			break;
	}
}



/***********************************************************************
     * Menu
     * translate

***********************************************************************/
void ach::Menu::translate()
{
	list_foreach(items)
		items[i]->translate();
}



/***********************************************************************
     * Menu
     * style

***********************************************************************/
void ach::Menu::style(ach::MenuTheme *_theme)
{
	theme = _theme;

	text->setFont(*theme->font);
	text->setFillColor(theme->color);

	box->setFillColor(theme->bg);
	box->setOutlineColor(theme->border);

	sfxBlip = theme->blip;
	sfxBack = theme->back;
	sfxPick = theme->pick;

	list_foreach(items)
		items[i]->style();

	calculate();
}
