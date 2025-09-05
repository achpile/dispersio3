#ifndef __MAP_OBJECT_NPC
#define __MAP_OBJECT_NPC


namespace ach
{
	struct MapObjectNPC : MapObject
	{
		ach::DataNPC *base;


		 MapObjectNPC(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectNPC();

		void touch();
	};
}

#endif
