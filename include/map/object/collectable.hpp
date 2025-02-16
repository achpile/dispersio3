#ifndef __MAP_OBJECT_COLLECTABLE
#define __MAP_OBJECT_COLLECTABLE


namespace ach
{
	struct MapObjectCollectable : MapObject
	{
		 MapObjectCollectable(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectCollectable();
	};
}

#endif
