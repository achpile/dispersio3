#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * findMapObject

***********************************************************************/
ach::MapObject* ach::Map::findMapObject(int id)
{
	list_foreach(objects)
		if (objects[i]->id == id)
			return objects[i];

	return NULL;
}
