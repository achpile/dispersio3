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
bool ach::PhysLine::check(ach::Phys *phys)
{
	d = 0.0f;
	o = 0.0f;

	if (type == ach::PhysType::ptPlatform && (v || phys->jumpdown || phys->vel.y < 0.0f))
		return false;

	if (!collision_box_vs_line(phys->rect, line))
		return false;


	float left  = std::min(projection_vector(line.a, v), projection_vector(line.b, v));
	float right = std::max(projection_vector(line.a, v), projection_vector(line.b, v));

	o = std::min(projection_rect_tip(phys->rect, v), right) - std::max(projection_rect_pos(phys->rect, v), left);

	if (o == 0.0f)
		return false;


	float d1 = 0.0f;
	float d2 = 0.0f;

	d1 = diff(projection_rect_pos(phys->rect, v), projection_rect_pos(phys->rect, !v), projection_rect_tip(phys->rect, !v), false);
	d2 = diff(projection_rect_tip(phys->rect, v), projection_rect_pos(phys->rect, !v), projection_rect_tip(phys->rect, !v), true );


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
     * offset

***********************************************************************/
sf::Vector2f ach::PhysLine::offset()
{
	sf::Vector2f result(0.0f, 0.0f);

	if (v) result.x = d;
	else   result.y = d;

	return result;
}



/***********************************************************************
     * PhysLineSort
     * operator()

***********************************************************************/
bool ach::PhysLineSort::operator()(ach::PhysLine *a, ach::PhysLine *b)
{
	return a->o > b->o;
}
