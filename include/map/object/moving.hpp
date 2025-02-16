#ifndef __MAP_OBJECT_MOVING
#define __MAP_OBJECT_MOVING


namespace ach
{
	struct MapObjectMoving : MapObject
	{
		 MapObjectMoving(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectMoving();
	};
}

#endif
