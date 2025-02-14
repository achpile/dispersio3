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
	cam       = new ach::Camera(this);

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

	checkpoints.clear();

	list_delete(characters);
	list_delete(objects);
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
	stars->update();

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
	stars->render();

	renderTiles();

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
	for (int x = cam->tiles.left; x < cam->tiles.left + cam->tiles.width; x++)
		for (int y = cam->tiles.top; y < cam->tiles.top + cam->tiles.height; y++)
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
void ach::Map::viewport(sf::Vector2f v)
{
	cam->pos.x = floor(v.x / cam->viewport.width );
	cam->pos.y = floor(v.y / cam->viewport.height);

	cam->calc();

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
	list_foreach(objects)
		if (objects[i]->phys.rect.intersects(character->phys.rect))
		{
			objects[i]->use();
			return;
		}
}
