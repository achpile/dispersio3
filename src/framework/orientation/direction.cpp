#include "meta/headers.hpp"


/***********************************************************************
     * operator!

***********************************************************************/
ach::Direction operator!(ach::Direction d)
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



/***********************************************************************
     * dir_orient

***********************************************************************/
ach::Orientation dir_orient(ach::Direction d)
{
	switch (d)
	{
		case ach::Direction::dUp   : return ach::Orientation::oVertical;
		case ach::Direction::dDown : return ach::Orientation::oVertical;
		case ach::Direction::dLeft : return ach::Orientation::oHorizontal;
		case ach::Direction::dRight: return ach::Orientation::oHorizontal;
		case ach::Direction::dCount: return ach::Orientation::oCount;
	}

	return ach::Orientation::oCount;
}



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
     * dir_sign

***********************************************************************/
int dir_sign(ach::Direction d)
{
	switch (d)
	{
		case ach::Direction::dUp   : return -1;
		case ach::Direction::dDown : return  1;
		case ach::Direction::dLeft : return -1;
		case ach::Direction::dRight: return  1;
		case ach::Direction::dCount: return  0;
	}

	return 0;
}
