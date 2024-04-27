#include "meta/headers.hpp"


/***********************************************************************
     * PhysLine
     * constructor

***********************************************************************/
ach::PhysLine::PhysLine(sf::Vector2f _a, sf::Vector2f _l, sf::Vector2f pos, bool _solid)
{
	a = _a + pos;
	b = _l + a;
	l = _l;

	solid = _solid;
	len   = vector_len(l);
}



/***********************************************************************
     * PhysLine
     * destructor

***********************************************************************/
ach::PhysLine::~PhysLine()
{
}
