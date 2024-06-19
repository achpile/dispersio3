#ifndef __OBJECT_DECOR
#define __OBJECT_DECOR


namespace ach
{
	struct MapObjectDecor : MapObject
	{
		 MapObjectDecor(json_t *obj);
		~MapObjectDecor();
	};
}

#endif
