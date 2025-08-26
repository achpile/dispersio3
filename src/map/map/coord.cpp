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
     * getTileCoord

***********************************************************************/
sf::Vector2i ach::Map::getTileCoord(sf::Vector2f v)
{
	return sf::Vector2i(v.x / sizeTile.x, v.y / sizeTile.y);
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
     * getTileRect

***********************************************************************/
sf::FloatRect ach::Map::getTileRect(sf::Vector2i v)
{
	return sf::FloatRect(getTilePos(v), sf::Vector2f(sizeTile));
}
