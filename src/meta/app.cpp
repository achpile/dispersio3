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
	db        = new ach::Database();
	settings  = new ach::Settings();
	theme     = new ach::Theme();
	cache     = new ach::Cache();
	joystick  = new ach::Joystick();
	ctrl      = new ach::ControlPad();

	lm        = new ach::LanguageManager();
	rm        = new ach::RenderManager();
	mm        = new ach::MusicManager();
	sm        = new ach::SoundManager();
	tm        = new ach::TimeManager();

	stars     = new ach::ParticleSystemStars(RENDER_LAYER_BG_X, RENDER_LAYER_BG_Y, 70);

	rm->initLayer(ach::RenderLayer::rlBG    , RENDER_LAYER_BG_X  , RENDER_LAYER_BG_Y  , settings->isSmooth());
	rm->initLayer(ach::RenderLayer::rlGame  , RENDER_LAYER_GAME_X, RENDER_LAYER_GAME_Y, settings->isSmooth());
	rm->initLayer(ach::RenderLayer::rlEffect, RENDER_LAYER_GAME_X, RENDER_LAYER_GAME_Y, settings->isSmooth());
	rm->initLayer(ach::RenderLayer::rlFront , RENDER_LAYER_GAME_X, RENDER_LAYER_GAME_Y, settings->isSmooth());
	rm->initLayer(ach::RenderLayer::rlGUI   , RENDER_LAYER_GUI_X , RENDER_LAYER_GUI_Y , settings->isSmooth());

	create();
	resize();

	db->load();
	tm->init();

	stars->realtime = true;
	stars->layer    = ach::RenderLayer::rlBG;

	lm->refresh();
	theme->refresh();

	stateSet(ach::GameState::gsStart);
}



/***********************************************************************
     * App
     * destructor

***********************************************************************/
ach::App::~App()
{
	delete settings;
	delete theme;
	delete cache;
	delete stars;
	delete db;
	delete state;
	delete window;
	delete logger;
	delete joystick;
	delete ctrl;

	delete lm;
	delete rm;
	delete mm;
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

	events();
	stateSwitch();

	if (!isFocused)
		return;

	window->clear();
	rm->clear();
	rm->reset();

	joystick->update();
	ctrl->update();
	state->update();

	mm->update();
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


		case sf::Event::JoystickConnected:
			joystick->connection(e.joystickConnect.joystickId, true);
			break;


		case sf::Event::JoystickDisconnected:
			joystick->connection(e.joystickConnect.joystickId, false);
			break;


		default:
			break;
	}

	if (state)
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
		case ach::GameState::gsGame   : state = new ach::StateGame   (); return;
		case ach::GameState::gsCredits: state = new ach::StateCredits(); return;
		case ach::GameState::gsFinish : state = new ach::StateFinish (); return;
		case ach::GameState::gsEnd    : state = new ach::StateEnd    (); return;
	}

	state->translate();
	state->style();
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

	sf::Image *icon;

	sfml_load_image(&icon, json_object_get_branch_string(dm->data, "Meta.GFX.Icon"));

	window = new sf::RenderWindow(settings->getWindowMode(),
	                              PROJECT_NAME " v" PROJECT_VERS,
	                              settings->getWindowStyle());

	window->setMouseCursorVisible(true);
	window->setFramerateLimit(settings->getFrameRate());
	window->setVerticalSyncEnabled(true);
	window->setPosition(settings->getWindowPosition());
	window->setIcon(icon->getSize().x,
	                icon->getSize().y,
	                icon->getPixelsPtr());

	delete icon;
}
