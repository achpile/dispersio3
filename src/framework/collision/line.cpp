#include "meta/headers.hpp"


/***********************************************************************
     * PhysLine
     * constructor

***********************************************************************/
ach::PhysLine::PhysLine(ach::PhysType _type, sf::Vector2f _a, sf::Vector2f _b, sf::Vector2f pos)
{
	a    = _a + pos;
	b    = _b + pos;
	type = _type;

	calc();
}



/***********************************************************************
     * PhysLine
     * destructor

***********************************************************************/
ach::PhysLine::~PhysLine()
{
}



/***********************************************************************
     * PhysLine
     * calc

***********************************************************************/
void ach::PhysLine::calc()
{
	l   = b - a;
	len = vector_len(l);
}



/*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*
                       Fast Ray-Box Intersection
                           by Andrew Woo
              from "Graphics Gems", Academic Press, 1990
*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*/
/***********************************************************************
     * PhysLine
     * collideBox

***********************************************************************/
bool ach::PhysLine::collideBox(sf::FloatRect box, sf::Vector2f *c, sf::Vector2f *n)
{
	sf::Vector2i quad;

	sf::Vector2f max(-1.0f, -1.0f);
	sf::Vector2f candidate;

	sf::Vector2f coord;
	sf::Vector2f normal;

	bool  plane;
	float dist;


	quad.x = interval_side(a.x, box.left, box.left + box.width );
	quad.y = interval_side(a.y, box.top , box.top  + box.height);

	candidate.x = box.left;
	candidate.y = box.top;

	if (quad.x == SIDE_RIGHT)
		candidate.x += box.width;

	if (quad.y == SIDE_RIGHT)
		candidate.y += box.height;


	if (!quad.x && !quad.y)
	{
		if (c) *c = sf::Vector2f(a.x , a.y );
		if (n) *n = sf::Vector2f(0.0f, 0.0f);

		return true;
	}


	if (quad.x && l.x != 0.0f)
		max.x = (candidate.x - a.x) / l.x;

	if (quad.y && l.y != 0.0f)
		max.y = (candidate.y - a.y) / l.y;


	plane = (max.x < max.y);

	if ((plane && max.y < 0.0f) || (!plane && max.x < 0.0f))
		return false;


	if (plane)
	{
		coord.x = a.x + max.y * l.x;
		coord.y = candidate.y;

		normal.x = 0;
		normal.y = quad.y;

		if (!interval_check(coord.x, box.left, box.left + box.width))
			return false;
	}
	else
	{
		coord.x = candidate.x;
		coord.y = a.y + max.x * l.y;

		normal.x = quad.x;
		normal.y = 0;

		if (!interval_check(coord.y, box.top, box.top + box.height))
			return false;
	}


	dist = vector_len(sf::Vector2f(coord.x - a.x, coord.y - a.y));

	if (dist > len)
		return false;

	if (c) *c = coord;
	if (n) *n = normal;

	return true;
}
