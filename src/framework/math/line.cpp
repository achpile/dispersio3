#include "meta/headers.hpp"


/***********************************************************************
     * Line
     * constructor

***********************************************************************/
ach::Line::Line()
{
}



/***********************************************************************
     * Line
     * destructor

***********************************************************************/
ach::Line::~Line()
{
}



/***********************************************************************
     * Line
     * set

***********************************************************************/
void ach::Line::set(sf::Vector2f _a, sf::Vector2f _b)
{
	a = _a;
	b = _b;

	calc();
}



/***********************************************************************
     * Line
     * calc

***********************************************************************/
void ach::Line::calc()
{
	v = b - a;
	l = vector_len(v);
	n = vector_norm(vector_perpendicular(v));

	r.left   = std::min(a.x, b.x);
	r.top    = std::min(a.y, b.y);
	r.width  = fabs(a.x - b.x);
	r.height = fabs(a.y - b.y);
}
