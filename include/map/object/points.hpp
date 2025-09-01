#ifndef __MAP_OBJECT_POINTS
#define __MAP_OBJECT_POINTS


namespace ach
{
	struct MapObjectPoints : MapObject
	{
		ach::DataSound *sfx;
		ach::Timer      blinking;


		 MapObjectPoints(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectPoints();

		void reset();
		void handle();
		void touch();
	};
}

#endif
