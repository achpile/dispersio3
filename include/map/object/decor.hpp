#ifndef __MAP_OBJECT_DECOR
#define __MAP_OBJECT_DECOR


namespace ach
{
	struct MapObjectDecor : MapObject
	{
		 MapObjectDecor(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectDecor();
	};
}

#endif
