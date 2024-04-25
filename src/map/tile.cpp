#include "meta/headers.hpp"


/***********************************************************************
     * Tile
     * constructor

***********************************************************************/
ach::Tile::Tile(const char *filename, int _id)
{
	id  = _id;
	spr = new ach::Sprite(filename, false, false);
}



/***********************************************************************
     * Tile
     * destructor

***********************************************************************/
ach::Tile::~Tile()
{
	delete spr;
}
