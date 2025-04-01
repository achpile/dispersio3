#include "meta/headers.hpp"


/***********************************************************************
     * MapTile
     * constructor

***********************************************************************/
ach::MapTile::MapTile()
{
	back  = NULL;
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
	renderTile(back , pos, ach::RenderLayer::rlGame );
	renderTile(wall , pos, ach::RenderLayer::rlGame );
	renderTile(block, pos, ach::RenderLayer::rlFront);
	renderTile(decor, pos, ach::RenderLayer::rlFront);
}



/***********************************************************************
     * MapTile
     * renderTile

***********************************************************************/
void ach::MapTile::renderTile(ach::Tile *tile, sf::Vector2f pos, ach::RenderLayer layer)
{
	if (!tile)
		return;

	tile->spr->spr->setPosition(pos);
	rm->draw(tile->spr->spr, layer);
}



/***********************************************************************
     * MapTile
     * set

***********************************************************************/
void ach::MapTile::set(ach::Tile *tile, ach::TileLayer layer)
{
	switch (layer)
	{
		case ach::TileLayer::tlBack : back  = tile; break;
		case ach::TileLayer::tlWall : wall  = tile; break;
		case ach::TileLayer::tlBlock: block = tile; break;
		case ach::TileLayer::tlDecor: decor = tile; break;
	}
}
