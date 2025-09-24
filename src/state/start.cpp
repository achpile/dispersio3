#include "meta/headers.hpp"


/***********************************************************************
     * StateStart
     * constructor

***********************************************************************/
ach::StateStart::StateStart()
{
	sprites.push_back(new ach::Sprite("data/base/gfx/ui/start/01.png", false, true));
	sprites.push_back(new ach::Sprite("data/base/gfx/ui/start/02.png", false, true));
	sprites.push_back(new ach::Sprite("data/base/gfx/ui/start/03.png", false, true));
	sprites.push_back(new ach::Sprite("data/base/gfx/ui/start/04.png", false, true));

	slideshow = new ach::SlideShow(&sprites, true);

	app->mouse(false);
	db->getTrack(json_object_get_branch_string(dm->data, "Meta.Track.Menu"))->play();

	slideshow->setDuration(4.0f);
	slideshow->setPosition(sf::Vector2f(RENDER_LAYER_GUI_X / 2, RENDER_LAYER_GUI_Y / 2));
}



/***********************************************************************
     * StateStart
     * destructor

***********************************************************************/
ach::StateStart::~StateStart()
{
	list_delete(sprites);

	delete slideshow;
}



/***********************************************************************
     * StateStart
     * update

***********************************************************************/
void ach::StateStart::update()
{
	slideshow->update();
	stars->update();

	if (!slideshow->active)
		app->stateSet(ach::GameState::gsMenu);

	render();
}



/***********************************************************************
     * StateStart
     * render

***********************************************************************/
void ach::StateStart::render()
{
	stars->render();
	slideshow->render();
}



/***********************************************************************
     * StateStart
     * event

***********************************************************************/
void ach::StateStart::event(sf::Event e)
{
	switch (e.type)
	{
		case sf::Event::MouseButtonReleased:
		case sf::Event::KeyPressed:
		case sf::Event::JoystickButtonPressed:
			slideshow->next();

		default:
			break;
	}
}
