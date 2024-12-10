#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * findMapArea

***********************************************************************/
ach::MapArea* ach::Map::findMapArea(sf::Vector2f v)
{
	list_foreach(areas)
		if (areas[i]->rect.contains(v))
			return areas[i];

	return NULL;
}



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
