#include "meta/headers.hpp"


/***********************************************************************
     * PhysLine
     * constructor

***********************************************************************/
ach::PhysLine::PhysLine(ach::PhysType _type, sf::Vector2f a, sf::Vector2f b, sf::Vector2f pos)
{
	type = _type;

	line.set(a + pos, b + pos);
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
	v = (fabs(line.v.x) < fabs(line.v.y));
	k = projection_vector(line.v, !v) / projection_vector(line.v, v);
}



/***********************************************************************
     * PhysLine
     * check

***********************************************************************/
bool ach::PhysLine::check(ach::Phys *p)
{
	d = 0.0f;
	o = 0.0f;

	if (type == ach::PhysType::ptPlatform && (v || p->jumpdown || p->vel.y < 0.0f))
		return false;

	if (!collision_box_vs_line(p->rect, line))
		return false;


	float left  = std::min(projection_vector(line.a, v), projection_vector(line.b, v));
	float right = std::max(projection_vector(line.a, v), projection_vector(line.b, v));

	o = std::min(projection_rect_tip(p->rect, v), right) - std::max(projection_rect_pos(p->rect, v), left);

	if (o == 0.0f)
		return false;


	float d1 = 0.0f;
	float d2 = 0.0f;

	d1 = diff(projection_rect_pos(p->rect, v), projection_rect_pos(p->rect, !v), projection_rect_tip(p->rect, !v), false);
	d2 = diff(projection_rect_tip(p->rect, v), projection_rect_pos(p->rect, !v), projection_rect_tip(p->rect, !v), true );


	d = (fabs(d1) > fabs(d2)) ? d1 : d2;

	if (type == ach::PhysType::ptPlatform && !interval_check(d, -2.0f, 0.0f))
	{
		d = 0.0f;
		return false;
	}

	return true;
}



/***********************************************************************
     * PhysLine
     * check

***********************************************************************/
bool ach::PhysLine::check(ach::Line *)
{
	d = 0.0f;
	o = 0.0f;

	return false;
}



/***********************************************************************
     * PhysLine
     * collide

***********************************************************************/
bool ach::PhysLine::collide(ach::Phys *p)
{
	if ((d == 0.0f) || (o == 0.0f))
		return false;


	sf::Vector2f offset = offsetPhys();

	if (offset.y < 0.0f)
		p->grounded = true;

	if (offset.y != 0.0f)
		p->vel.y = 0.0f;

	if (offset.x != 0.0f)
	{
		p->moving = false;
		p->vel.x  = 0.0f;
	}

	p->pos += offset;
	p->calc();

	return true;
}



/***********************************************************************
     * PhysLine
     * collide

***********************************************************************/
bool ach::PhysLine::collide(ach::Line *l)
{
	if (d == 0.0f)
		return false;

	if (o == 0.0f)
		return false;


	sf::Vector2f offset = offsetLine(l);

	l->b -= offset;

	return true;
}



/***********************************************************************
     * PhysLine
     * offsetPhys

***********************************************************************/
sf::Vector2f ach::PhysLine::offsetPhys()
{
	sf::Vector2f result(0.0f, 0.0f);

	if (v) result.x = d;
	else   result.y = d;

	return result;
}



/***********************************************************************
     * PhysLine
     * offsetLine

***********************************************************************/
sf::Vector2f ach::PhysLine::offsetLine(ach::Line *)
{
	sf::Vector2f result(0.0f, 0.0f);

	return result;
}



/***********************************************************************
     * PhysLine
     * diff

***********************************************************************/
float ach::PhysLine::diff(float x, float left, float right, bool max)
{
	float val;

	if (interval_check(x, projection_vector(line.a, v), projection_vector(line.b, v)))
		val = value(x);
	else if (max)
		val = value(std::max(projection_vector(line.a, v), projection_vector(line.b, v)));
	else
		val = value(std::min(projection_vector(line.a, v), projection_vector(line.b, v)));


	if (!interval_check(val, left, right))
		return 0.0f;

	return (val - left < right - val) ? val - left : val - right;
}



/***********************************************************************
     * PhysLine
     * value

***********************************************************************/
float ach::PhysLine::value(float x)
{
	return math_linear(x - projection_vector(line.a, v), k, projection_vector(line.a, !v));
}



/***********************************************************************
     * PhysLine
     * sort

***********************************************************************/
bool ach::PhysLine::sort(ach::PhysLine *a, ach::PhysLine *b)
{
	return a->o > b->o;
}



/***********************************************************************
     * PhysLine
     * remove

***********************************************************************/
bool ach::PhysLine::remove(ach::PhysLine *l)
{
	return (l->d == 0.0f) || (l->o == 0.0f);
}
