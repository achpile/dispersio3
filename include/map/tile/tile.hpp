#ifndef __MAP_TILE_TILE
#define __MAP_TILE_TILE


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
