#ifndef __MAP_TILESET
#define __MAP_TILESET


namespace ach
{
	struct Tileset
	{
		std::vector<ach::Tile*> tiles;


		 Tileset();
		~Tileset();

		void load(const char *path, json_t *tileset);
		void sort();
	};
}

#endif
