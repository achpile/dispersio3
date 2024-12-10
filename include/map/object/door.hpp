#ifndef __MAP_OBJECT_DOOR
#define __MAP_OBJECT_DOOR


namespace ach
{
	struct MapObjectDoor : MapObject
	{
		ach::MapObjectDoor *pair;

		int id;


		 MapObjectDoor(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectDoor();

		void connect(ach::MapObjectDoor *_pair);
	};
}

#endif
