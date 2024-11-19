#ifndef __MAP_BASE
#define __MAP_BASE


namespace ach
{
	struct Map
	{
		std::vector<ach::Character*>  characters;
		std::vector<ach::MapObject*>  objects;
		std::vector<ach::Projectile*> projectiles;

		ach::ProcessWorld            *world;

		ach::MapTile ***tiles;
		ach::Tileset   *tileset;
		ach::Collision *collision;

		sf::Vector2i    sizeMap;
		sf::Vector2i    sizeTile;
		sf::Vector2f    spawn;


		 Map(ach::ProcessWorld *_world, const char *filename);
		~Map();

		void update();
		void render(sf::FloatRect viewport);

		void renderTiles(sf::FloatRect viewport);

		void process();

		void collide();
		void collidePhysSteps(ach::Phys *phys);
		bool collidePhys(ach::Phys *phys);
		void collideProjectile(ach::Projectile *projectile);
		void collideExplosion(ach::Projectile *projectile);
		void collideCharacter(ach::Character *character);

		void load(const char *filename);
		void loadMeta(json_t *mapdata);
		void loadInit();
		void loadTileset(json_t *mapdata, const char *path);
		void loadLayers(json_t *mapdata);
		void loadLayerTiles(json_t *layer);
		void loadLayerObjects(json_t *layer);
		void loadPhys(json_t *layer);
		void loadObjects(json_t *layer);
		void loadCharacters(json_t *layer);

		sf::Vector2f getTilePos(sf::Vector2i v);
		sf::Vector2f getTileCenter(sf::Vector2i v);
	};
}

#endif
