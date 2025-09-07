#ifndef __MAP_OBJECT_ARCADE
#define __MAP_OBJECT_ARCADE


namespace ach
{
	struct MapObjectArcade : MapObject
	{
		 MapObjectArcade(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectArcade();

		void touch();
		void use();
	};
}

#endif
