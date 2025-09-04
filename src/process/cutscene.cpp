#include "meta/headers.hpp"


/***********************************************************************
     * ProcessCutscene
     * constructor

***********************************************************************/
ach::ProcessCutscene::ProcessCutscene(ach::StateGame *_owner, ach::DataCutscene *cutscene) : Process(_owner)
{
	base = cutscene;
}



/***********************************************************************
     * ProcessCutscene
     * destructor

***********************************************************************/
ach::ProcessCutscene::~ProcessCutscene()
{
}



/***********************************************************************
     * ProcessCutscene
     * update

***********************************************************************/
void ach::ProcessCutscene::update()
{
}



/***********************************************************************
     * ProcessCutscene
     * render

***********************************************************************/
void ach::ProcessCutscene::render()
{
}



/***********************************************************************
     * ProcessCutscene
     * event

***********************************************************************/
void ach::ProcessCutscene::event(sf::Event e)
{
	switch (e.type)
	{
		case sf::Event::MouseButtonReleased:
		case sf::Event::KeyPressed:
		case sf::Event::JoystickButtonPressed:
			owner->finish();

		default:
			break;
	}
}
