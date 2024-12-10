#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * getTilePos

***********************************************************************/
sf::Vector2f ach::Map::getTilePos(sf::Vector2i v)
{
	return vector_mult(sizeTile, v);
}



/***********************************************************************
     * Map
     * getTileCenter

***********************************************************************/
sf::Vector2f ach::Map::getTileCenter(sf::Vector2i v)
{
	return getTilePos(v) + sf::Vector2f(sizeTile) / 2.0f;
}



/***********************************************************************
     * Map
     * getMapArea

***********************************************************************/
sf::FloatRect ach::Map::getMapArea(sf::Vector2f v)
{
	list_foreach(areas)
		if (areas[i]->rect.contains(v))
			return areas[i]->rect;

	return sf::FloatRect(sf::Vector2f(0, 0), vector_mult(sizeMap, sizeTile));
}
