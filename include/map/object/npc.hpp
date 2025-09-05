#ifndef __MAP_OBJECT_NPC
#define __MAP_OBJECT_NPC


namespace ach
{
	struct MapObjectNPC : MapObject
	{
		ach::DataNPC   *base;
		ach::Direction  face;

		sf::Vector2f    spawn;


		 MapObjectNPC(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectNPC();

		void reset();
		void touch();
	};
}

#endif
