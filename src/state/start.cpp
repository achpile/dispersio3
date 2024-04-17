#include "meta/headers.hpp"


/***********************************************************************
     * StateStart
     * constructor

***********************************************************************/
ach::StateStart::StateStart()
{
	index  = 0;
	offset = 0.0f;

	sprites.push_back(new ach::Sprite("data/base/gfx/gui/start/01.png", false, true));
	sprites.push_back(new ach::Sprite("data/base/gfx/gui/start/02.png", false, true));
	sprites.push_back(new ach::Sprite("data/base/gfx/gui/start/03.png", false, true));
	sprites.push_back(new ach::Sprite("data/base/gfx/gui/start/04.png", false, true));
}



/***********************************************************************
     * StateStart
     * destructor

***********************************************************************/
ach::StateStart::~StateStart()
{
	listDelete(sprites);
}



/***********************************************************************
     * StateStart
     * update

***********************************************************************/
void ach::StateStart::update()
{
	offset += tm->frame;

	if (offset > START_FADE_SLOPE * 2 + START_FADE_LENGTH)
		next();

	if (index >= sprites.size())
		exit(0); // switch to menu

	bg->stars->update();

	render();
}



/***********************************************************************
     * StateStart
     * render

***********************************************************************/
void ach::StateStart::render()
{
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
	if ((e.type == sf::Event::MouseButtonReleased) || (e.type == sf::Event::KeyReleased))
		next();
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
