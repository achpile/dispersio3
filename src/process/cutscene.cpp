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
	text->setPosition(sf::Vector2f(CUTSCENE_LEFT, RENDER_LAYER_GUI_Y));
	text->setWidth(RENDER_LAYER_GUI_X - CUTSCENE_LEFT * 2);
	text->setAlign(ach::TextAlign::taCenter);
	text->setSpacing(theme->cutscene->spacing() + CUTSCENE_SPACING);

	slideshow->setPosition(sf::Vector2f(RENDER_LAYER_GUI_X / 2, 200.0f));
	slideshow->setDuration((text->height() + CUTSCENE_HEIGHT - text->spacing) / (CUTSCENE_SPEED * base->slideshow.size()));

	base->track->play();
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
	text->pos.y -= tm->get(true) * CUTSCENE_SPEED;

	slideshow->update();

	if (!slideshow->active)
		finish();

	render();
}



/***********************************************************************
     * ProcessCutscene
     * render

***********************************************************************/
void ach::ProcessCutscene::render()
{
	sf::Color color;

	slideshow->render();

	list_foreach(text->strings)
	{
		color    = theme->cutscene->color;
		color.a *= math_fade((text->top(i) - (RENDER_LAYER_GUI_Y - CUTSCENE_HEIGHT)) / (CUTSCENE_HEIGHT), 0.25f);

		text->print(i, color);
	}
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
			finish();

		default:
			break;
	}
}



/***********************************************************************
     * ProcessCutscene
     * finish

***********************************************************************/
void ach::ProcessCutscene::finish()
{
	active = false;

	cache->cutscene();
}
