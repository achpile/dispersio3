#ifndef __MAP_OBJECT_SOLID
#define __MAP_OBJECT_SOLID


namespace ach
{
	struct MapObjectSolid : MapObject
	{
		 MapObjectSolid(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectSolid();
	};
}

#endif
