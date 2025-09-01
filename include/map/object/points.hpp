#ifndef __MAP_OBJECT_POINTS
#define __MAP_OBJECT_POINTS


namespace ach
{
	struct MapObjectPoints : MapObject
	{
		ach::DataSound *sfx;


		 MapObjectPoints(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectPoints();

		void touch();
	};
}

#endif
