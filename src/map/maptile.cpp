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
     * set

***********************************************************************/
void ach::MapTile::set(ach::Tile *tile, ach::TileLayer layer)
{
	switch (layer)
	{
		case ach::TileLayer::tlWall : wall  = tile; break;
		case ach::TileLayer::tlBlock: block = tile; break;
		case ach::TileLayer::tlDecor: decor = tile; break;

		default: wall = tile;
	}
}
