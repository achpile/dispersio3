#ifndef __MAP_TILE_TILESET
#define __MAP_TILE_TILESET


namespace ach
{
	struct Tileset
	{
		std::vector<ach::Tile*> tiles;


		 Tileset();
		~Tileset();

		void load(const char *path, json_t *tileset);

		ach::Tile* get(unsigned int id);
	};
}

#endif
