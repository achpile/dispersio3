#include "meta/headers.hpp"


/***********************************************************************
     * App
     * constructor

***********************************************************************/
ach::App::App()
{
	isRunning = true;
	isFocused = true;

	window    = NULL;
	state     = NULL;

	stateCurr = ach::GameState::gsNone;

	logger    = new ach::Log();
	dm        = new ach::Datamodel();
	settings  = new ach::Settings();
	lang      = new ach::Language();
	resources = new ach::Resources();
	bg        = new ach::Background();
	ctrl      = new ach::ControlPad();

	create();

	rm        = new ach::RenderManager();
	sm        = new ach::SoundManager();
	tm        = new ach::TimeManager();

	resize();
	tm->init();

	stateSet(ach::GameState::gsStart);
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
	delete sm;
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

	isFocused = window->hasFocus();
	isRunning = window->isOpen();

	stateSwitch();
	events();

	if (!isFocused)
		return;

	window->clear();
	rm->clear();

	ctrl->update();
	state->update();
	sm->update();

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
	switch (e.type)
	{
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
     * stateSet

***********************************************************************/
void ach::App::stateSet(ach::GameState s)
{
	stateNext = s;
}



/***********************************************************************
     * App
     * stateSwitch

***********************************************************************/
void ach::App::stateSwitch()
{
	if (stateCurr == stateNext)
		return;

	if (stateCurr != ach::GameState::gsNone)
		delete state;

	stateCurr = stateNext;

	ctrl->reset();

	switch (stateCurr)
	{
		case ach::GameState::gsNone   : state = NULL                   ; return;
		case ach::GameState::gsStart  : state = new ach::StateStart  (); return;
		case ach::GameState::gsMenu   : state = new ach::StateMenu   (); return;
		case ach::GameState::gsCredits: state = new ach::StateCredits(); return;
		case ach::GameState::gsGame   : state = new ach::StateGame   (); return;
	}
}



/***********************************************************************
     * App
     * mouse

***********************************************************************/
void ach::App::mouse(bool visible)
{
	window->setMouseCursorVisible(visible);
}



/***********************************************************************
     * App
     * create

***********************************************************************/
void ach::App::create()
{
	if (window)
		delete window;

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
