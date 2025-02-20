#ifndef __MAP_OBJECT_FRAGILE
#define __MAP_OBJECT_FRAGILE


namespace ach
{
	struct MapObjectFragile : MapObject
	{
		 MapObjectFragile(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectFragile();
	};
}

#endif
