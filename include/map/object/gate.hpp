#ifndef __MAP_OBJECT_GATE
#define __MAP_OBJECT_GATE


namespace ach
{
	struct MapObjectGate : MapObject
	{
		ach::DataSound *sfx;


		 MapObjectGate(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectGate();

		void reset();
		void close();
	};
}

#endif
