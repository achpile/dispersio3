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

	cam->setArea(sf::FloatRect(sf::Vector2f(0, 0), vector_mult(map->sizeMap, map->sizeTile)));
	cam->follow(&player->phys);

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

	list_delete(gfx);
}



/***********************************************************************
     * ProcessWorld
     * update

***********************************************************************/
void ach::ProcessWorld::update()
{
	map->update();
	cam->update();

	list_update(gfx);

	render();
}



/***********************************************************************
     * ProcessWorld
     * render

***********************************************************************/
void ach::ProcessWorld::render()
{
	map->render(cam->viewport);

	list_render(gfx);
}
