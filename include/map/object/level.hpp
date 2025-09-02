#ifndef __MAP_OBJECT_LEVEL
#define __MAP_OBJECT_LEVEL


namespace ach
{
	struct MapObjectLevel : MapObject
	{
		ach::LevelMode type;


		 MapObjectLevel(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectLevel();

		void touch();
		void use();
	};
}

#endif
