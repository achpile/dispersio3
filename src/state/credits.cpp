#include "meta/headers.hpp"


/***********************************************************************
     * StateCredits
     * constructor

***********************************************************************/
ach::StateCredits::StateCredits()
{
}



/***********************************************************************
     * StateCredits
     * destructor

***********************************************************************/
ach::StateCredits::~StateCredits()
{
}



/***********************************************************************
     * StateCredits
     * update

***********************************************************************/
void ach::StateCredits::update()
{
	bg->stars->update();

	render();
}



/***********************************************************************
     * StateCredits
     * render

***********************************************************************/
void ach::StateCredits::render()
{
}



/***********************************************************************
     * StateCredits
     * event

***********************************************************************/
void ach::StateCredits::event(sf::Event e)
{
	if ((e.type == sf::Event::MouseButtonReleased) || (e.type == sf::Event::KeyReleased))
		app->stateSet(ach::GameState::gsMenu);
}
