#include "meta/headers.hpp"


/***********************************************************************
     * ProcessWorld
     * constructor

***********************************************************************/
ach::ProcessWorld::ProcessWorld()
{
	map    = new ach::Map(this, PATH_BASE "/" "maps/test.tmj");
	cam    = new ach::Camera();
	player = new ach::Character(this, db->getCharacter("Player"), map->spawn);

	cam->follow(&player->phys);
	cam->set(map->findMapArea(player->phys.pos));

	player->respawning = true;

	map->characters.push_back(player);
}



/***********************************************************************
     * ProcessWorld
     * destructor

***********************************************************************/
ach::ProcessWorld::~ProcessWorld()
{
	delete map;
	delete cam;
}



/***********************************************************************
     * ProcessWorld
     * update

***********************************************************************/
void ach::ProcessWorld::update()
{
	map->update();
	cam->update();

	map->touch(player);

	if (!cam->check())
		cam->set(map->findMapArea(player->phys.pos));

	render();
}



/***********************************************************************
     * ProcessWorld
     * render

***********************************************************************/
void ach::ProcessWorld::render()
{
	map->render(cam->viewport);
}



/***********************************************************************
     * ProcessWorld
     * gateway

***********************************************************************/
void ach::ProcessWorld::gateway(sf::FloatRect dest)
{
	player->gateway(dest);

	cam->update();

	if (!cam->check())
		cam->set(map->findMapArea(player->phys.pos));
}
