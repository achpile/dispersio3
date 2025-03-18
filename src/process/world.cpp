#include "meta/headers.hpp"


/***********************************************************************
     * ProcessWorld
     * constructor

***********************************************************************/
ach::ProcessWorld::ProcessWorld(ach::StateGame *_owner) : Process(_owner)
{
	state  = ach::WorldState::wsFadeIn;
	map    = new ach::Map(this, db->getMap("01-MilitaryBase"));
	player = new ach::Character(this, map->base->player, map->spawn);

	map->cam->follow(&player->phys);
	map->characters.push_back(player);
}



/***********************************************************************
     * ProcessWorld
     * destructor

***********************************************************************/
ach::ProcessWorld::~ProcessWorld()
{
	delete map;
}



/***********************************************************************
     * ProcessWorld
     * update

***********************************************************************/
void ach::ProcessWorld::update()
{
	prepare();

	map->update();
	map->touch(player);

	render();
	finalize();
}



/***********************************************************************
     * ProcessWorld
     * render

***********************************************************************/
void ach::ProcessWorld::render()
{
	map->render();
}



/***********************************************************************
     * ProcessWorld
     * prepare

***********************************************************************/
void ach::ProcessWorld::prepare()
{
}



/***********************************************************************
     * ProcessWorld
     * finalize

***********************************************************************/
void ach::ProcessWorld::finalize()
{
}



/***********************************************************************
     * ProcessWorld
     * gateway

***********************************************************************/
void ach::ProcessWorld::gateway(sf::FloatRect dest)
{
	player->gateway(dest);
	map->cam->update();
}



/***********************************************************************
     * ProcessWorld
     * goal

***********************************************************************/
void ach::ProcessWorld::goal()
{
	owner->next();
}
