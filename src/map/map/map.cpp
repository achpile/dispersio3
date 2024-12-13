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
	parallax  = new ach::Parallax(base->parallax);

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
	delete parallax;

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
	process();
	collide();

	cam->update();

	if (base->stars)
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
	if (base->stars)
		stars->render();

	parallax->render(cam->viewport.left);

	renderTiles(cam->viewport);

	list_render(objects);
	list_render(characters);
	list_render(gfx);
	list_render(projectiles);
}



/***********************************************************************
     * Map
     * renderTiles

***********************************************************************/
void ach::Map::renderTiles(sf::FloatRect viewport)
{
	sf::Vector2i from;
	sf::Vector2i to;


	from.x = viewport.left / sizeTile.x - 1;
	from.y = viewport.top  / sizeTile.y - 1;

	to.x = (viewport.left + viewport.width ) / sizeTile.x + 1;
	to.y = (viewport.top  + viewport.height) / sizeTile.y + 1;


	from.x = std::max(from.x, 0);
	from.y = std::max(from.y, 0);

	to.x = std::min(to.x, sizeMap.x);
	to.y = std::min(to.y, sizeMap.y);


	for (int x = from.x; x < to.x; x++)
		for (int y = from.y; y < to.y; y++)
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
