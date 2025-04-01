#ifndef __MAP_OBJECT_WATER
#define __MAP_OBJECT_WATER


namespace ach
{
	struct MapObjectWater : MapObject
	{
		 MapObjectWater(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectWater();

		void touch();
	};
}

#endif
