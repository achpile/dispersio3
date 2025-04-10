#ifndef __MAP_OBJECT_YOKU
#define __MAP_OBJECT_YOKU


namespace ach
{
	struct MapObjectYoku : MapObject
	{
		ach::DataSound *sfx;


		 MapObjectYoku(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectYoku();

		void reset();
		void handle();
	};
}

#endif
