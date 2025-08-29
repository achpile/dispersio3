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
     * findMapSpawn

***********************************************************************/
sf::FloatRect ach::Map::findMapSpawn(int id)
{
	if (id == -1)
		return spawn;

	list_foreach(checkpoints)
		if (checkpoints[i]->id == id)
		{
			checkpoints[i]->active = true;
			checkpoints[i]->animate();

			return checkpoints[i]->phys.rect;
		}

	return spawn;
}
