#include "meta/headers.hpp"


/***********************************************************************
     * Cabinet
     * constructor

***********************************************************************/
ach::Cabinet::Cabinet()
{
	game    = ach::Arcade::create();
	cabinet = new ach::Sprite(json_object_get_branch_string(dm->data, "Meta.GFX.Cabinet"), false, false);

	cabinet->spr->setPosition((RENDER_LAYER_GUI_X - cabinet->size.x) / 2.0f, RENDER_LAYER_GUI_Y - cabinet->size.y);
}



/***********************************************************************
     * Cabinet
     * destructor

***********************************************************************/
ach::Cabinet::~Cabinet()
{
	delete game;
	delete cabinet;
}



/***********************************************************************
     * Cabinet
     * update

***********************************************************************/
void ach::Cabinet::update()
{
	game->controls();
	game->update();
}



/***********************************************************************
     * Cabinet
     * render

***********************************************************************/
void ach::Cabinet::render()
{
	game->render();

	rm->draw(cabinet->spr, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * Cabinet
     * init

***********************************************************************/
void ach::Cabinet::init()
{
	delete game;

	game = ach::Arcade::create();
}



/***********************************************************************
     * Cabinet
     * active

***********************************************************************/
bool ach::Cabinet::active()
{
	if (!game)
		return false;

	return game->active;
}
