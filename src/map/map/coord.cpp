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
