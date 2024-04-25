#ifndef __MAP_MAPTILE
#define __MAP_MAPTILE


namespace ach
{
	struct MapTile
	{
		ach::Tile *wall;
		ach::Tile *block;
		ach::Tile *decor;


		 MapTile();
		~MapTile();
	};
}

#endif
