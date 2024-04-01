#include "meta/headers.hpp"


/***********************************************************************
     * App
     * constructor

***********************************************************************/
ach::App::App()
{
	isRunning = true;
	isFocused = true;

	create();

	rm        = new ach::RenderManager();

	resources = new ach::Resources();
	state     = new ach::StateMenu();

	resize();
}



/***********************************************************************
     * App
     * destructor

***********************************************************************/
ach::App::~App()
{
	delete rm;

	delete state;
	delete resources;
	delete window;
}



/***********************************************************************
     * App
     * update

***********************************************************************/
void ach::App::update()
{
	events();

	isFocused = window->hasFocus();
	isRunning = window->isOpen();

	if (!isFocused)
		return;

	window->clear();
	rm->clear();

	state->update();

	rm->display(window);
	window->display();
}



/***********************************************************************
     * App
     * events

***********************************************************************/
void ach::App::events()
{
	sf::Event e;

	while (window->pollEvent(e))
		event(e);
}



/***********************************************************************
     * App
     * event

***********************************************************************/
void ach::App::event(sf::Event e)
{
	switch(e.type) {
		case sf::Event::Closed:
			window->close();
			break;


		case sf::Event::Resized:
			resize();
			break;


		default:
			break;
	}

	state->event(e);
}



/***********************************************************************
     * App
     * resize

***********************************************************************/
void ach::App::resize()
{
	rm->resize(window);
}



/***********************************************************************
     * App
     * create

***********************************************************************/
void ach::App::create()
{
	window = new sf::RenderWindow(sf::VideoMode(1280, 800, 32), // settings->getWindowMode
	                              PROJECT_NAME " v" PROJECT_VERS,
	                              sf::Style::Default);          // settings->getWindowStyle

	window->setMouseCursorVisible(true);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);

	// center window

	sf::Image icon;
	icon.loadFromFile("data/gfx/gui/misc/icon.png");

	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
