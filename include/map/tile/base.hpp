#ifndef __MAP_TILE_BASE
#define __MAP_TILE_BASE


namespace ach
{
	struct Tile
	{
		ach::Sprite  *spr;
		unsigned int  id;


		 Tile(const char *filename, unsigned int _id);
		~Tile();
	};
}

#endif
