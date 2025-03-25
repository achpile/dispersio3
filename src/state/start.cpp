#include "meta/headers.hpp"


/***********************************************************************
     * StateStart
     * constructor

***********************************************************************/
ach::StateStart::StateStart()
{
	index  = 0;
	offset = 0.0f;

	sprites.push_back(new ach::Sprite("data/base/gfx/ui/start/01.png", false, true));
	sprites.push_back(new ach::Sprite("data/base/gfx/ui/start/02.png", false, true));
	sprites.push_back(new ach::Sprite("data/base/gfx/ui/start/03.png", false, true));
	sprites.push_back(new ach::Sprite("data/base/gfx/ui/start/04.png", false, true));

	app->mouse(false);
	mm->play(json_object_get_branch_string(dm->data, "Meta.Track.Menu"));
}



/***********************************************************************
     * StateStart
     * destructor

***********************************************************************/
ach::StateStart::~StateStart()
{
	list_delete(sprites);
}



/***********************************************************************
     * StateStart
     * update

***********************************************************************/
void ach::StateStart::update()
{
	offset += tm->get(true);

	if (offset > START_FADE_SLOPE * 2 + START_FADE_LENGTH)
		next();

	if (index >= sprites.size())
	{
		app->stateSet(ach::GameState::gsMenu);
		return;
	}

	stars->update();

	render();
}



/***********************************************************************
     * StateStart
     * render

***********************************************************************/
void ach::StateStart::render()
{
	stars->render();

	sprites[index]->spr->setColor(sf::Color(255, 255, 255, 255 * math_fade(offset, START_FADE_SLOPE, START_FADE_LENGTH)));
	sprites[index]->spr->setPosition(RENDER_LAYER_GUI_X / 2, RENDER_LAYER_GUI_Y / 2);

	rm->draw(sprites[index]->spr, ach::RenderLayer::rlGUI);
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
			next();

		default:
			break;
	}
}



/***********************************************************************
     * StateStart
     * next

***********************************************************************/
void ach::StateStart::next()
{
	offset = 0.0f;
	index++;
}
