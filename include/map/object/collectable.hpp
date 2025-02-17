#ifndef __MAP_OBJECT_COLLECTABLE
#define __MAP_OBJECT_COLLECTABLE


namespace ach
{
	struct MapObjectCollectable : MapObject
	{
		ach::DataSound *sfx;


		 MapObjectCollectable(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectCollectable();

		void touch();
	};
}

#endif
