#include "meta/headers.hpp"


/***********************************************************************
     * ProcessCutscene
     * constructor

***********************************************************************/
ach::ProcessCutscene::ProcessCutscene(ach::StateGame *_owner, ach::DataCutscene *cutscene) : Process(_owner)
{
	base = cutscene;
	text = new ach::Text(&theme->menu);
	slideshow = new ach::SlideShow(&base->slideshow, true);

	text->setString(lm->get(base->text));
	text->setPosition(sf::Vector2f(TEXT_FLOW_LEFT, RENDER_LAYER_GUI_Y));

	mm->play(base->track);
}



/***********************************************************************
     * ProcessCutscene
     * destructor

***********************************************************************/
ach::ProcessCutscene::~ProcessCutscene()
{
	delete text;
	delete slideshow;
}



/***********************************************************************
     * ProcessCutscene
     * update

***********************************************************************/
void ach::ProcessCutscene::update()
{
	slideshow->update();

	if (!slideshow->active)
		owner->finish();
}



/***********************************************************************
     * ProcessCutscene
     * render

***********************************************************************/
void ach::ProcessCutscene::render()
{
	slideshow->render();
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
