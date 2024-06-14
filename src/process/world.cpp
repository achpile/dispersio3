#include "meta/headers.hpp"


/***********************************************************************
     * ProcessWorld
     * constructor

***********************************************************************/
ach::ProcessWorld::ProcessWorld()
{
	map    = new ach::Map(PATH_BASE "/" "maps/test.tmj");
	cam    = new ach::Camera();
	player = new ach::Player();

	cam->setArea(sf::FloatRect(sf::Vector2f(0, 0), vector_mult(map->sizeMap, map->sizeTile)));
	cam->follow(&player->character->phys);

	player->respawn(map->spawn);
}



/***********************************************************************
     * ProcessWorld
     * destructor

***********************************************************************/
ach::ProcessWorld::~ProcessWorld()
{
	delete map;
	delete cam;
	delete player;

	listDelete(projectiles);
}



/***********************************************************************
     * ProcessWorld
     * update

***********************************************************************/
void ach::ProcessWorld::update()
{
	player->controls();

	collision();

	player->update();
	cam->update();
	map->update();

	render();
}



/***********************************************************************
     * ProcessWorld
     * render

***********************************************************************/
void ach::ProcessWorld::render()
{
	map->render(cam->viewport);
	player->render();
}



/***********************************************************************
     * ProcessWorld
     * collision

***********************************************************************/
void ach::ProcessWorld::collision()
{
	map->collision->collide(&player->character->phys);
}
