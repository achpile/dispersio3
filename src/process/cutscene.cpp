#include "meta/headers.hpp"


/***********************************************************************
     * ProcessCutscene
     * constructor

***********************************************************************/
ach::ProcessCutscene::ProcessCutscene(ach::StateGame *_owner, ach::DataCutscene *cutscene) : Process(_owner)
{
	base      = cutscene;
	text      = new ach::Text(theme->cutscene);
	slideshow = new ach::SlideShow(&base->slideshow, true);

	text->setString(lm->get(base->text));
	text->setPosition(sf::Vector2f(TEXT_FLOW_LEFT, RENDER_LAYER_GUI_Y));
	text->setWidth(RENDER_LAYER_GUI_X - TEXT_FLOW_LEFT * 2);
	text->setAlign(ach::TextAlign::taCenter);

	slideshow->setPosition(sf::Vector2f(RENDER_LAYER_GUI_X / 2, 225.0f));
	slideshow->setDuration((text->height() + 350.0f) / (TEXT_FLOW_CUTSCENE * base->slideshow.size()));

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
	text->pos.y -= tm->get(true) * TEXT_FLOW_CUTSCENE;

	slideshow->update();

	if (!slideshow->active)
		owner->finish();

	render();
}



/***********************************************************************
     * ProcessCutscene
     * render

***********************************************************************/
void ach::ProcessCutscene::render()
{
	slideshow->render();
	text->render();
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
