#include "meta/headers.hpp"


/***********************************************************************
     * dir_vector

***********************************************************************/
sf::Vector2i dir_vector(ach::Direction d)
{
	switch (d)
	{
		case ach::Direction::dUp   : return sf::Vector2i( 0, -1);
		case ach::Direction::dDown : return sf::Vector2i( 0,  1);
		case ach::Direction::dLeft : return sf::Vector2i(-1,  0);
		case ach::Direction::dRight: return sf::Vector2i( 1,  0);
		case ach::Direction::dCount: return sf::Vector2i( 0,  0);
	}

	return sf::Vector2i(0, 0);
}



/***********************************************************************
     * dir_invert

***********************************************************************/
ach::Direction dir_invert(ach::Direction d)
{
	switch (d)
	{
		case ach::Direction::dUp   : return ach::Direction::dDown;
		case ach::Direction::dDown : return ach::Direction::dUp;
		case ach::Direction::dLeft : return ach::Direction::dRight;
		case ach::Direction::dRight: return ach::Direction::dLeft;
		case ach::Direction::dCount: return ach::Direction::dCount;
	}

	return ach::Direction::dCount;
}
