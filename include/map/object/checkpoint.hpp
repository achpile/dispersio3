#ifndef __MAP_OBJECT_CHECKPOINT
#define __MAP_OBJECT_CHECKPOINT


namespace ach
{
	struct MapObjectCheckpoint : MapObject
	{
		ach::Map       *map;
		ach::DataSound *sfx;

		bool active;


		 MapObjectCheckpoint(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectCheckpoint();

		void init(ach::Map *map);
		void touch();

		void animate();
		void deactivate();
	};
}

#endif
