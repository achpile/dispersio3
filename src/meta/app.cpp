#include "meta/headers.hpp"


/***********************************************************************
     * App
     * constructor

***********************************************************************/
ach::App::App()
{
	isRunning = true;
	isFocused = true;

	logger    = new ach::Log();
	dm        = new ach::Datamodel();
	settings  = new ach::Settings();
	lang      = new ach::Language();
	resources = new ach::Resources();
	bg        = new ach::Background();
	ctrl      = new ach::ControlPad();

	create();

	rm        = new ach::RenderManager();
	tm        = new ach::TimeManager();

	state     = new ach::StateMenu();

	resize();
	tm->init();
}



/***********************************************************************
     * App
     * destructor

***********************************************************************/
ach::App::~App()
{
	delete settings;
	delete bg;
	delete lang;
	delete state;
	delete resources;
	delete window;
	delete logger;
	delete ctrl;

	delete rm;
	delete tm;
	delete dm;
}



/***********************************************************************
     * App
     * update

***********************************************************************/
void ach::App::update()
{
	tm->update();
	events();

	isFocused = window->hasFocus();
	isRunning = window->isOpen();

	if (!isFocused)
		return;

	window->clear();
	rm->clear();

	ctrl->update();
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
	settings->setWindowSize(window->getSize());
	rm->resize(window);
}



/***********************************************************************
     * App
     * create

***********************************************************************/
void ach::App::create()
{
	window = new sf::RenderWindow(settings->getWindowMode(),
	                              PROJECT_NAME " v" PROJECT_VERS,
	                              settings->getWindowStyle());

	window->setMouseCursorVisible(true);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
	window->setPosition(settings->getWindowPosition());
	window->setIcon(resources->meta.icon->getSize().x,
	                resources->meta.icon->getSize().y,
	                resources->meta.icon->getPixelsPtr());
}
