#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * constructor

***********************************************************************/
ach::Map::Map(const char *filename)
{
	collision = new ach::Collision();

	load(filename);
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
}



/***********************************************************************
     * Map
     * update

***********************************************************************/
void ach::Map::update()
{
}



/***********************************************************************
     * Map
     * render

***********************************************************************/
void ach::Map::render(sf::FloatRect viewport)
{
	bg->stars->update();
	renderTiles(viewport);
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
			tiles[x][y]->render(vector_mult(sizeTile, sf::Vector2i(x, y)));
}
