#include "meta/headers.hpp"


/***********************************************************************
     * Quadrant
     * constructor

***********************************************************************/
ach::Quadrant::Quadrant(sf::Vector2i pos, sf::Vector2i size)
{
	rect = sf::FloatRect(sf::Vector2f(pos), sf::Vector2f(size));
}



/***********************************************************************
     * Quadrant
     * destructor

***********************************************************************/
ach::Quadrant::~Quadrant()
{
	lines.clear();
}
