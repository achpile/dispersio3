#include "meta/headers.hpp"


/***********************************************************************
     * PhysLine
     * constructor

***********************************************************************/
ach::PhysLine::PhysLine(ach::PhysType _type, sf::Vector2f _a, sf::Vector2f _b, sf::Vector2f pos)
{
	a = _a + pos;
	b = _b + pos;
	l = _b - _a;

	type = _type;
	len  = vector_len(l);
}



/***********************************************************************
     * PhysLine
     * destructor

***********************************************************************/
ach::PhysLine::~PhysLine()
{
}
