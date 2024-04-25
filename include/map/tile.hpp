#ifndef __MAP_TILE
#define __MAP_TILE


namespace ach
{
	struct Tile
	{
		ach::Sprite *spr;

		int id;


		 Tile(const char *filename, int _id);
		~Tile();
	};
}

#endif
