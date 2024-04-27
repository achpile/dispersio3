#ifndef __MAP_BASE
#define __MAP_BASE


namespace ach
{
	struct Map
	{
		ach::MapTile ***tiles;
		ach::Tileset   *tileset;
		ach::Collision *collision;

		sf::Vector2i    sizeMap;
		sf::Vector2i    sizeTile;


		 Map(const char *filename);
		~Map();

		void update();
		void render(sf::FloatRect viewport);

		void renderTiles(sf::FloatRect viewport);

		void load(const char *filename);
		void loadMeta(json_t *mapdata);
		void loadInit();
		void loadTileset(json_t *mapdata, const char *path);
		void loadLayers(json_t *mapdata);
		void loadLayerTiles(json_t *layer);
		void loadLayerObjects(json_t *layer);
		void loadPhys(json_t *layer);
	};
}

#endif
