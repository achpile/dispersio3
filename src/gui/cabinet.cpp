#include "meta/headers.hpp"


/***********************************************************************
     * Cabinet
     * constructor

***********************************************************************/
ach::Cabinet::Cabinet()
{
	game    = NULL;
	cabinet = new ach::Sprite(json_object_get_branch_string(dm->data, "Meta.GFX.Cabinet"), false, false);

	cabinet->spr->setPosition((RENDER_LAYER_GUI_X - cabinet->size.x) / 2.0f, RENDER_LAYER_GUI_Y - cabinet->size.y);
}



/***********************************************************************
     * Cabinet
     * destructor

***********************************************************************/
ach::Cabinet::~Cabinet()
{
	delete cabinet;

	if (game)
		delete game;
}



/***********************************************************************
     * Cabinet
     * update

***********************************************************************/
void ach::Cabinet::update()
{
	controls();

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
	rm->draw(game->spr   , ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * Cabinet
     * init

***********************************************************************/
void ach::Cabinet::init()
{
	load();
	select(0);
}



/***********************************************************************
     * Cabinet
     * load

***********************************************************************/
void ach::Cabinet::load()
{
	index = 0;

	games.clear();

	for (int i = ach::ArcadeGame::None; i < ach::ArcadeGame::Count; i++)
		//if (cache->getFlag(pair_get_string((ach::ArcadeGame)i, pairArcade)))
			games.push_back((ach::ArcadeGame)i);

	if (!games.size())
		games.push_back(ach::ArcadeGame::None);
}



/***********************************************************************
     * Cabinet
     * select

***********************************************************************/
void ach::Cabinet::select(int offset)
{
	index += offset;

	if (index >= (int)games.size())
		index = 0;

	if (index < 0)
		index = games.size();

	if (game)
		delete game;

	game = ach::Arcade::create(games[index], games.size() > 1);

	game->spr->setPosition(cabinet->spr->getPosition() + sf::Vector2f(116, 122));
}



/***********************************************************************
     * Cabinet
     * controls

***********************************************************************/
void ach::Cabinet::controls()
{
	game->controls();

	if (game->state != ach::ArcadeState::Title)
		return;

	if (games.size() < 2)
		return;

	if (ctrl->keys[ach::ControlAction::caLeft ].pressed) select(-1);
	if (ctrl->keys[ach::ControlAction::caRight].pressed) select( 1);
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
