#include "meta/headers.hpp"


/***********************************************************************
     * collision_box_vs_box

***********************************************************************/
bool collision_box_vs_box(sf::FloatRect box, sf::FloatRect rect, sf::Vector2f *c, sf::Vector2f *n)
{
	sf::FloatRect intersection;

	if (!box.intersects(rect, intersection))
		return false;

	if (c) *c = rect_center(intersection);
	if (n) *n = vector_norm(rect_center(box) - rect_center(rect));

	return true;
}



/***********************************************************************
     * collision_box_vs_circle

***********************************************************************/
bool collision_box_vs_circle(sf::FloatRect box, sf::Vector2f center, float r, sf::Vector2f *c, sf::Vector2f *n)
{
	sf::Vector2f t;

	t.x = center.x;
	t.y = center.y;

	if (center.x < box.left)             t.x = box.left;
	if (center.x > box.left + box.width) t.x = box.left + box.width;

	if (center.y < box.top             ) t.y = box.top;
	if (center.y > box.top + box.height) t.y = box.top + box.height;

	if (sqrt(math_sqr(center.x - t.x) + math_sqr(center.y - t.y)) > r)
		return false;

	if (c) *c = rect_center(box);
	if (n) *n = vector_norm(rect_center(box) - center);

	return true;
}



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
		return false;


	float r = n1 / d;
	float s = n2 / d;

	if (!interval_check(r, 0.0f, 1.0f) || !interval_check(s, 0.0f, 1.0f))
		return false;

	sf::Vector2f coord = line.a + line.v * r;

	if (c) *c = coord;
	if (n) *n = vector_alike(vector_norm(solid.n), coord - line.a);

	return true;
}
