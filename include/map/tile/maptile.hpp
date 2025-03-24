#ifndef __MAP_TILE_MAPTILE
#define __MAP_TILE_MAPTILE


namespace ach
{
	enum TileLayer
	{
		tlBack = 0,
		tlWall,
		tlBlock,
		tlDecor
	};


	struct MapTile
	{
		ach::Tile *back;
		ach::Tile *wall;
		ach::Tile *block;
		ach::Tile *decor;


		 MapTile();
		~MapTile();

		void render(sf::Vector2f pos);
		void renderTile(ach::Tile *tile, sf::Vector2f pos);
		void set(ach::Tile *tile, ach::TileLayer layer);
	};
}

#endif
