#include "meta/headers.hpp"


/***********************************************************************
     * ProcessWorld
     * constructor

***********************************************************************/
ach::ProcessWorld::ProcessWorld()
{
	map    = new ach::Map(PATH_BASE "/" "maps/test.tmj");
	cam    = new ach::Camera();
	player = new ach::Character(this, db->getCharacter("Player"));

	cam->setArea(sf::FloatRect(sf::Vector2f(0, 0), vector_mult(map->sizeMap, map->sizeTile)));
	cam->follow(&player->phys);

	player->respawn(map->spawn);

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
