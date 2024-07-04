#include "meta/headers.hpp"


/*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*
                       Fast Ray-Box Intersection
                           by Andrew Woo
              from "Graphics Gems", Academic Press, 1990
*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*/
/***********************************************************************
     * collision_box_vs_line

***********************************************************************/
bool collision_box_vs_line(sf::FloatRect box, ach::Line line, sf::Vector2f *c, sf::Vector2f *n)
{
	sf::Vector2i quad;

	sf::Vector2f max(-1.0f, -1.0f);
	sf::Vector2f candidate;

	sf::Vector2f coord;
	sf::Vector2f normal;

	bool  plane;
	float dist;


	quad.x = interval_side(line.a.x, box.left, box.left + box.width );
	quad.y = interval_side(line.a.y, box.top , box.top  + box.height);

	candidate.x = box.left;
	candidate.y = box.top;

	if (quad.x == SIDE_RIGHT)
		candidate.x += box.width;

	if (quad.y == SIDE_RIGHT)
		candidate.y += box.height;


	if (!quad.x && !quad.y)
	{
		if (c) *c = sf::Vector2f(line.a.x, line.a.y);
		if (n) *n = sf::Vector2f(0.0f    , 0.0f    );

		return true;
	}


	if (quad.x && line.v.x != 0.0f)
		max.x = (candidate.x - line.a.x) / line.v.x;

	if (quad.y && line.v.y != 0.0f)
		max.y = (candidate.y - line.a.y) / line.v.y;


	plane = (max.x < max.y);

	if ((plane && max.y < 0.0f) || (!plane && max.x < 0.0f))
		return false;


	if (plane)
	{
		coord.x = line.a.x + max.y * line.v.x;
		coord.y = candidate.y;

		normal.x = 0;
		normal.y = quad.y;

		if (!interval_check(coord.x, box.left, box.left + box.width))
			return false;
	}
	else
	{
		coord.x = candidate.x;
		coord.y = line.a.y + max.x * line.v.y;

		normal.x = quad.x;
		normal.y = 0;

		if (!interval_check(coord.y, box.top, box.top + box.height))
			return false;
	}


	dist = vector_len(sf::Vector2f(coord.x - line.a.x, coord.y - line.a.y));

	if (dist > line.l)
		return false;

	if (c) *c = coord;
	if (n) *n = normal;

	return true;
}
