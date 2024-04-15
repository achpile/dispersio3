#include "meta/headers.hpp"


/***********************************************************************
     * StateMenu
     * constructor

***********************************************************************/
ach::StateMenu::StateMenu()
{
	menu = new ach::Menu("Main");

	menu->setPosition(sf::Vector2f(100.0f, 100.0f));
	menu->setWidth(400.0f);
	menu->setHeight(6);

	fill();
}



/***********************************************************************
     * StateMenu
     * destructor

***********************************************************************/
ach::StateMenu::~StateMenu()
{
	delete menu;
}



/***********************************************************************
     * StateMenu
     * update

***********************************************************************/
void ach::StateMenu::update()
{
	if (!menu->isActive)
		app->isRunning = false;

	render();

	menu->controls();
	menu->update();
}



/***********************************************************************
     * StateMenu
     * render

***********************************************************************/
void ach::StateMenu::render()
{
	bg->stars->update();
}



/***********************************************************************
     * StateMenu
     * event

***********************************************************************/
void ach::StateMenu::event(sf::Event e)
{
	switch(e.type)
	{
		case sf::Event::MouseMoved:
			hover(rm->transform(sf::Vector2f(e.mouseMove.x, e.mouseMove.y), ach::RenderLayer::rlGUI));
			break;


		case sf::Event::MouseButtonReleased:
			if ((e.mouseButton.button != sf::Mouse::Button::Left) && (e.mouseButton.button == sf::Mouse::Button::Right))
				break;

			click(rm->transform(sf::Vector2f(e.mouseMove.x, e.mouseMove.y), ach::RenderLayer::rlGUI), e.mouseButton.button == sf::Mouse::Button::Left);
			break;


		default:
			break;
	}
}



/***********************************************************************
     * StateMenu
     * hover

***********************************************************************/
void ach::StateMenu::hover(sf::Vector2f )
{
}



/***********************************************************************
     * StateMenu
     * click

***********************************************************************/
void ach::StateMenu::click(sf::Vector2f , bool )
{
}



/***********************************************************************
     * StateMenu
     * fill

***********************************************************************/
void ach::StateMenu::fill()
{
	menu->add(new ach::MenuItemFolder(menu, "Start"  ), "Main");
	menu->add(new ach::MenuItemFolder(menu, "Options"), "Main");

	menu->add(new ach::MenuItemFolder(menu, "Game"   ), "Options");
	menu->add(new ach::MenuItemFolder(menu, "Video"  ), "Options");
	menu->add(new ach::MenuItemFolder(menu, "Audio"  ), "Options");

	menu->finalize();
}
