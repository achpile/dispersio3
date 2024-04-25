#ifndef __MAP_MAPTILE
#define __MAP_MAPTILE


namespace ach
{
	enum TileLayer
	{
		tlWall = 0,
		tlBlock,
		tlDecor
	};


	struct MapTile
	{
		ach::Tile *wall;
		ach::Tile *block;
		ach::Tile *decor;


		 MapTile();
		~MapTile();

		void set(ach::Tile *tile, ach::TileLayer layer);
	};
}

#endif
