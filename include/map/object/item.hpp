#ifndef __MAP_OBJECT_ITEM
#define __MAP_OBJECT_ITEM


namespace ach
{
	struct MapObjectItem : MapObject
	{
		ach::DataItem  *base;
		ach::DataSound *sfx;


		 MapObjectItem(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectItem();

		void touch();
	};
}

#endif
