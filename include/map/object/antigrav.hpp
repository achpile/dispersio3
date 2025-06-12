#ifndef __MAP_OBJECT_ANTIGRAV
#define __MAP_OBJECT_ANTIGRAV


namespace ach
{
	struct MapObjectAntigrav : MapObject
	{
		ach::DataSound *sfx;


		 MapObjectAntigrav(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectAntigrav();

		void stand(ach::Phys *p);
	};
}

#endif
