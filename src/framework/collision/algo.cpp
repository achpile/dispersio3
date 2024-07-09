#include "meta/headers.hpp"


/*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*
                       Fast Ray-Box Intersection
                           by Andrew Woo
              from "Graphics Gems", Academic Press, 1990
*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*/
/***********************************************************************
     * collision_box_vs_line

***********************************************************************/
bool collision_box_vs_line(sf::FloatRect box, ach::Line solid, sf::Vector2f *c, sf::Vector2f *n)
{
	sf::Vector2i quad;

	sf::Vector2f max(-1.0f, -1.0f);
	sf::Vector2f candidate;

	sf::Vector2f coord;
	sf::Vector2f normal;

	bool  plane;
	float dist;


	quad.x = interval_side(solid.a.x, box.left, box.left + box.width );
	quad.y = interval_side(solid.a.y, box.top , box.top  + box.height);

	candidate.x = box.left;
	candidate.y = box.top;

	if (quad.x == SIDE_RIGHT)
		candidate.x += box.width;

	if (quad.y == SIDE_RIGHT)
		candidate.y += box.height;


	if (!quad.x && !quad.y)
	{
		if (c) *c = sf::Vector2f(solid.a.x, solid.a.y);
		if (n) *n = sf::Vector2f(0.0f    , 0.0f    );

		return true;
	}


	if (quad.x && solid.v.x != 0.0f)
		max.x = (candidate.x - solid.a.x) / solid.v.x;

	if (quad.y && solid.v.y != 0.0f)
		max.y = (candidate.y - solid.a.y) / solid.v.y;


	plane = (max.x < max.y);

	if ((plane && max.y < 0.0f) || (!plane && max.x < 0.0f))
		return false;


	if (plane)
	{
		coord.x = solid.a.x + max.y * solid.v.x;
		coord.y = candidate.y;

		normal.x = 0;
		normal.y = quad.y;

		if (!interval_check(coord.x, box.left, box.left + box.width))
			return false;
	}
	else
	{
		coord.x = candidate.x;
		coord.y = solid.a.y + max.x * solid.v.y;

		normal.x = quad.x;
		normal.y = 0;

		if (!interval_check(coord.y, box.top, box.top + box.height))
			return false;
	}


	dist = vector_len(sf::Vector2f(coord.x - solid.a.x, coord.y - solid.a.y));

	if (dist > solid.l)
		return false;

	if (c) *c = coord;
	if (n) *n = normal;

	return true;
}



/***********************************************************************
     * collision_line_vs_line

***********************************************************************/
bool collision_line_vs_line(ach::Line line, ach::Line solid, sf::Vector2f *c, sf::Vector2f *n)
{
	float d  = ( line.v.x * solid.v.y) - (line.v.y * solid.v.x);
	float n1 = ((line.a.y - solid.a.y) * solid.v.x) - ((line.a.x - solid.a.x) * solid.v.y);
	float n2 = ((line.a.y - solid.a.y) * line.v.x ) - ((line.a.x - solid.a.x) * line.v.y );

	if (d == 0.0f)
	{
		if (n1 == 0.0f && n2 == 0.0f)
			return false;

		// get C
		// get N

		return true;
	}


	float r = n1 / d;
	float s = n2 / d;

	if (!interval_check(r, 0.0f, 1.0f) || !interval_check(s, 0.0f, 1.0f))
		return false;

	sf::Vector2f coord = line.a + line.v * r;

	if (c) *c = coord;
	if (n) *n = vector_alike(vector_norm(vector_perpendicular(solid.v)), coord - line.a);

	return true;
}
