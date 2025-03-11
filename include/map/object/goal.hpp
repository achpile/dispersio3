#ifndef __MAP_OBJECT_GOAL
#define __MAP_OBJECT_GOAL


namespace ach
{
	struct MapObjectGoal : MapObject
	{
		ach::DataSound *sfx;


		 MapObjectGoal(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectGoal();

		void touch();
	};
}

#endif
