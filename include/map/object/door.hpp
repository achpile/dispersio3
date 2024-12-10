#ifndef __MAP_OBJECT_DOOR
#define __MAP_OBJECT_DOOR


namespace ach
{
	struct MapObjectDoor : MapObject
	{
		 MapObjectDoor(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectDoor();
	};
}

#endif
