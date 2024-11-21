#include "meta/headers.hpp"


/***********************************************************************
     * vector_dot

***********************************************************************/
float vector_dot(sf::Vector2f a, sf::Vector2f b)
{
	return (a.x * b.x) + (a.y * b.y);
}



/***********************************************************************
     * vector_len

***********************************************************************/
float vector_len(sf::Vector2f v)
{
	return sqrt((v.x * v.x) + (v.y * v.y));
}



/***********************************************************************
     * vector_angle

***********************************************************************/
float vector_angle(sf::Vector2f v)
{
	return atan2(v.y, v.x);
}



/***********************************************************************
     * vector_create

***********************************************************************/
sf::Vector2f vector_create(float a)
{
	return sf::Vector2f(cos(a), sin(a));
}



/***********************************************************************
     * vector_perpendicular

***********************************************************************/
sf::Vector2f vector_perpendicular(sf::Vector2f v)
{
	return sf::Vector2f(v.y, -v.x);
}



/***********************************************************************
     * vector_alike

***********************************************************************/
sf::Vector2f vector_alike(sf::Vector2f v, sf::Vector2f a)
{
	return (vector_dot(v, a) >= 0.0f) ? v : -v;
}



/***********************************************************************
     * vector_mirror

***********************************************************************/
sf::Vector2f vector_mirror(sf::Vector2f v, sf::Vector2f n)
{
	return v - vector_set_len(vector_norm(n), 2 * vector_dot(v, n));
}



/***********************************************************************
     * vector_center

***********************************************************************/
sf::Vector2f vector_center(sf::FloatRect r)
{
	return sf::Vector2f(r.left + r.width / 2.0f, r.top + r.height / 2.0f);
}



/***********************************************************************
     * vector_norm

***********************************************************************/
sf::Vector2f vector_norm(sf::Vector2f v)
{
	return v / vector_len(v);
}



/***********************************************************************
     * vector_set_len

***********************************************************************/
sf::Vector2f vector_set_len(sf::Vector2f v, float l)
{
	return vector_norm(v) * l;
}



/***********************************************************************
     * vector_bisector

***********************************************************************/
sf::Vector2f vector_bisector(sf::Vector2f a, sf::Vector2f b)
{
	return vector_norm(vector_norm(a) + vector_norm(b));
}



/***********************************************************************
     * vector_mult

***********************************************************************/
sf::Vector2f vector_mult(sf::Vector2f a, sf::Vector2f b)
{
	return sf::Vector2f(a.x * b.x, a.y * b.y);
}



/***********************************************************************
     * vector_mult

***********************************************************************/
sf::Vector2f vector_mult(sf::Vector2i a, sf::Vector2i b)
{
	return sf::Vector2f(a.x * b.x, a.y * b.y);
}



/***********************************************************************
     * vector_mult_i

***********************************************************************/
sf::Vector2i vector_mult_i(sf::Vector2i a, sf::Vector2i b)
{
	return sf::Vector2i(a.x * b.x, a.y * b.y);
}



/***********************************************************************
     * vector_json_coord

***********************************************************************/
sf::Vector2f vector_json_coord(json_t *j, const char *x, const char *y)
{
	return sf::Vector2f(json_object_get_real(j, x),
	                    json_object_get_real(j, y));
}



/***********************************************************************
     * vector_json_rect

***********************************************************************/
sf::FloatRect vector_json_rect(json_t *j)
{
	return sf::FloatRect(json_object_get_real(j, "x"     ),
	                     json_object_get_real(j, "y"     ),
	                     json_object_get_real(j, "width" ),
	                     json_object_get_real(j, "height"));
}



/***********************************************************************
     * vector_json_center

***********************************************************************/
sf::Vector2f vector_json_center(json_t *j)
{
	return sf::Vector2f(json_object_get_real(j, "x"     ) + json_object_get_real(j, "width" ) / 2.0f,
	                    json_object_get_real(j, "y"     ) + json_object_get_real(j, "height") / 2.0f);
}



/***********************************************************************
     * vector_tile_coord

***********************************************************************/
sf::Vector2f vector_tile_coord(int x, int y, int size)
{
	return sf::Vector2f(x * size,
	                    y * size);
}



/***********************************************************************
     * vector_tile_center

***********************************************************************/
sf::Vector2f vector_tile_center(int x, int y, int size)
{
	return sf::Vector2f(x * size + size / 2,
	                    y * size + size / 2);
}



/***********************************************************************
     * vector_tile_bottom

***********************************************************************/
sf::Vector2f vector_tile_bottom(int x, int y, int size)
{
	return sf::Vector2f(x * size + size / 2,
	                    y * size + y);
}
