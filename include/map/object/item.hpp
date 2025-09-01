#ifndef __MAP_OBJECT_ITEM
#define __MAP_OBJECT_ITEM


namespace ach
{
	struct MapObjectItem : MapObject
	{
		ach::DataItem  *base;
		ach::DataSound *sfx;
		ach::Timer      blinking;


		 MapObjectItem(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectItem();

		void reset();
		void handle();
		void touch();
	};
}

#endif
