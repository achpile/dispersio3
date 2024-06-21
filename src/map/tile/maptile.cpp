#include "meta/headers.hpp"


/***********************************************************************
     * MapTile
     * constructor

***********************************************************************/
ach::MapTile::MapTile()
{
	wall  = NULL;
	block = NULL;
	decor = NULL;
}



/***********************************************************************
     * MapTile
     * destructor

***********************************************************************/
ach::MapTile::~MapTile()
{
}



/***********************************************************************
     * MapTile
     * render

***********************************************************************/
void ach::MapTile::render(sf::Vector2f pos)
{
	renderTile(wall , pos);
	renderTile(block, pos);
	renderTile(decor, pos);
}



/***********************************************************************
     * MapTile
     * renderTile

***********************************************************************/
void ach::MapTile::renderTile(ach::Tile *tile, sf::Vector2f pos)
{
	if (!tile)
		return;

	tile->spr->spr->setPosition(pos);
	rm->draw(tile->spr->spr, ach::RenderLayer::rlGame);
}



/***********************************************************************
     * MapTile
     * set

***********************************************************************/
void ach::MapTile::set(ach::Tile *tile, ach::TileLayer layer)
{
	switch (layer)
	{
		case ach::TileLayer::tlWall : wall  = tile; break;
		case ach::TileLayer::tlBlock: block = tile; break;
		case ach::TileLayer::tlDecor: decor = tile; break;
	}
}
