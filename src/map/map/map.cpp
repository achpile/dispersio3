#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * constructor

***********************************************************************/
ach::Map::Map(ach::ProcessWorld *_world, ach::DataMap *_base)
{
	base      = _base;
	world     = _world;
	collision = new ach::Collision();
	selector  = new ach::Selector();
	cam       = new ach::Camera(this);
	caption   = new ach::MapCaption(lm->getv("Game.Map.%s.Name", base->name));

	load();
}



/***********************************************************************
     * Map
     * destructor

***********************************************************************/
ach::Map::~Map()
{
	for (int x = 0; x < sizeMap.x; x++)
	{
		for (int y = 0; y < sizeMap.y; y++)
			delete tiles[x][y];

		delete tiles[x];
	}

	delete tiles;
	delete tileset;
	delete collision;
	delete cam;
	delete selector;
	delete caption;

	checkpoints.clear();

	list_delete(characters);
	list_delete(objects);
	list_delete(areas);
	list_delete(gfx);
	list_delete(projectiles);
}



/***********************************************************************
     * Map
     * update

***********************************************************************/
void ach::Map::update()
{
	solids.clear();

	process();
	collide();

	cam->update();
	caption->update();
	selector->update();

	list_update(characters);
	list_update(objects);
	list_update(gfx);
	list_update(projectiles);
}



/***********************************************************************
     * Map
     * render

***********************************************************************/
void ach::Map::render()
{
	renderTiles();

	caption->render();
	selector->render();

	list_render(objects);
	list_render(characters);
	list_render(gfx);
	list_render(projectiles);
}



/***********************************************************************
     * Map
     * renderTiles

***********************************************************************/
void ach::Map::renderTiles()
{
	sf::Vector2i from = getTileCoord(rect_lt(cam->viewport));
	sf::Vector2i to   = getTileCoord(rect_rb(cam->viewport));

	from.x = interval_set(from.x, 0, to.x);
	from.y = interval_set(from.y, 0, to.x);

	to.x   = interval_set(to.x, from.x, sizeMap.x - 1);
	to.y   = interval_set(to.y, from.y, sizeMap.y - 1);

	for (int x = from.x; x <= to.x; x++)
		for (int y = from.y; y <= to.y; y++)
			tiles[x][y]->render(getTilePos(sf::Vector2i(x, y)));
}



/***********************************************************************
     * Map
     * process

***********************************************************************/
void ach::Map::process()
{
	list_foreach(characters)
		characters[i]->process();

	list_foreach(objects)
		objects[i]->process();
}



/***********************************************************************
     * Map
     * viewport

***********************************************************************/
void ach::Map::viewport()
{
	list_delete(projectiles);
	list_delete(gfx);

	list_foreach(objects)
		objects[i]->reset();

	list_foreach(characters)
		if (characters[i]->enemy)
			characters[i]->respawn();
}



/***********************************************************************
     * Map
     * touch

***********************************************************************/
void ach::Map::touch(ach::Character* character)
{
	if (!character->alive)
		return;

	list_foreach(objects)
		if (objects[i]->phys.rect.intersects(character->phys.rect))
			objects[i]->touch();
}



/***********************************************************************
     * Map
     * use

***********************************************************************/
void ach::Map::use(ach::Character* character)
{
	if (!character->alive)
		return;

	list_foreach(objects)
		if (objects[i]->phys.rect.intersects(character->phys.rect))
		{
			objects[i]->use();
			return;
		}
}
