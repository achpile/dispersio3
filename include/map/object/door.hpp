#ifndef __MAP_OBJECT_DOOR
#define __MAP_OBJECT_DOOR


namespace ach
{
	struct MapObjectDoor : MapObject
	{
		sf::FloatRect gateway;

		int pair;


		 MapObjectDoor(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectDoor();

		void init(ach::Map *map);
		void use();
	};
}

#endif
