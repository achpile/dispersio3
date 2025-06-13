#include "meta/headers.hpp"


/***********************************************************************
     * PhysLine
     * constructor

***********************************************************************/
ach::PhysLine::PhysLine(ach::MapObject *_owner)
{
	type  = ach::PhysType::ptSolid;
	owner = _owner;
}



/***********************************************************************
     * PhysLine
     * constructor

***********************************************************************/
ach::PhysLine::PhysLine(ach::PhysType _type, sf::Vector2f a, sf::Vector2f b, sf::Vector2f pos)
{
	type  = _type;
	owner = NULL;

	set(a + pos, b + pos);
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
     * set

***********************************************************************/
void ach::PhysLine::set(sf::Vector2f a, sf::Vector2f b)
{
	line.set(a, b);
	calc();
}



/***********************************************************************
     * PhysLine
     * calc

***********************************************************************/
void ach::PhysLine::calc()
{
	o = orient_get(line);
	k = orient_v_coord(!o, line.v) / orient_v_coord(o, line.v);
}



/***********************************************************************
     * PhysLine
     * check

***********************************************************************/
bool ach::PhysLine::check(ach::Phys *p, long filter)
{
	d = 0.0f;
	f = 0.0f;

	if (!flag_get(filter, type))
		return false;

	if (type == ach::PhysType::ptPlatform && (o == ach::Orientation::oVertical || p->jumpdown || p->vel.y < 0.0f))
		return false;

	if (!collision_box_vs_line(p->rect, line))
		return false;


	float left  = std::min(orient_v_coord(o, line.a), orient_v_coord(o, line.b));
	float right = std::max(orient_v_coord(o, line.a), orient_v_coord(o, line.b));

	f = std::min(orient_rect_max(o, p->rect), right) - std::max(orient_rect_min(o, p->rect), left);

	if (f == 0.0f)
		return false;


	float d1 = 0.0f;
	float d2 = 0.0f;

	d1 = diff(orient_rect_min(o, p->rect), orient_rect_min(!o, p->rect), orient_rect_max(!o, p->rect), false);
	d2 = diff(orient_rect_max(o, p->rect), orient_rect_min(!o, p->rect), orient_rect_max(!o, p->rect), true );


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
bool ach::PhysLine::check(ach::Line *l, long filter)
{
	d = 0.0f;
	f = 0.0f;

	if (!flag_get(filter, type))
		return false;

	sf::Vector2f c;

	if (!collision_line_vs_line(*l, line, &c))
		return false;

	f = vector_len(l->b - c);
	d = l->l - f;

	return false;
}



/***********************************************************************
     * PhysLine
     * collide

***********************************************************************/
bool ach::PhysLine::collide(ach::Phys *p)
{
	if (math_epsilon(d) || (math_epsilon(f)))
		return false;

	if (f < 0)
		return false;

	if (o == ach::Orientation::oHorizontal && d * p->gravity < 0 && p->vel.y * p->gravity < 0.0f)
		return false;

	if (type == ach::PhysType::ptDeath)
		return true;

	sf::Vector2f offset = offsetPhys();


	p->pos += offset;
	p->calc();


	if (math_sign(offset.y))
	{
		if (math_sign(offset.y) == -math_sign(p->acc.y))
		{
			if (type == ach::PhysType::ptBounce)
			{
				p->vel.y  *= -1.0f;
				p->bounce  =  true;

				if (fabs(p->vel.y) < PHYS_MIN_BOUNCE)
					p->vel.y = math_sign(p->vel.y) * PHYS_MIN_BOUNCE;

				return true;
			}

			p->grounded = true;
			p->slope    = fabs(line.n.x);

			if (owner)
				owner->stand(p);
		}

		if (math_sign(offset.y) == -math_sign(p->vel.y))
			p->vel.y = 0.0f;
	}
	else
	{
		p->moving = false;
		p->vel.x  = 0.0f;
	}

	return true;
}



/***********************************************************************
     * PhysLine
     * collide

***********************************************************************/
bool ach::PhysLine::collide(ach::Line *l)
{
	if (math_epsilon(d) || (math_epsilon(f)))
		return false;

	l->b -= vector_set_len(l->v, f);

	if (owner)
		owner->hit();

	return true;
}



/***********************************************************************
     * PhysLine
     * offsetPhys

***********************************************************************/
sf::Vector2f ach::PhysLine::offsetPhys()
{
	return orient_v_create(!o) * d;
}



/***********************************************************************
     * PhysLine
     * diff

***********************************************************************/
float ach::PhysLine::diff(float x, float left, float right, bool max)
{
	float val;

	if (interval_check(x, orient_v_coord(o, line.a), orient_v_coord(o, line.b)))
		val = value(x);
	else if (max)
		val = value(std::max(orient_v_coord(o, line.a), orient_v_coord(o, line.b)));
	else
		val = value(std::min(orient_v_coord(o, line.a), orient_v_coord(o, line.b)));


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
	return math_linear(x - orient_v_coord(o, line.a), k, orient_v_coord(!o, line.a));
}



/***********************************************************************
     * PhysLine
     * sort

***********************************************************************/
bool ach::PhysLine::sort(ach::PhysLine *a, ach::PhysLine *b)
{
	return fabs(a->f) > fabs(b->f);
}



/***********************************************************************
     * PhysLine
     * remove

***********************************************************************/
bool ach::PhysLine::remove(ach::PhysLine *l)
{
	return (math_epsilon(l->d)) || (math_epsilon(l->f));
}
