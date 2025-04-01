#include "meta/headers.hpp"


/***********************************************************************
     * AICrawl
     * constructor

***********************************************************************/
ach::AICrawl::AICrawl(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	initial = pair_get_enum(json_class_get_string(obj, "Moving", "Direction"), pairDirection);

	if (dir_orient(initial) == ach::Orientation::oVertical)
		initial = ach::Direction::dRight;
}



/***********************************************************************
     * AICrawl
     * destructor

***********************************************************************/
ach::AICrawl::~AICrawl()
{
}



/***********************************************************************
     * AICrawl
     * physics

***********************************************************************/
void ach::AICrawl::physics()
{
	ground();
	check();
}



/***********************************************************************
     * AICrawl
     * control

***********************************************************************/
void ach::AICrawl::control()
{
	owner->dir.x      = dir_sign(dir);
	owner->phys.vel.x = dir_sign(dir) * owner->speed;
}



/***********************************************************************
     * AICrawl
     * reset

***********************************************************************/
void ach::AICrawl::reset()
{
	dir = initial;
}



/***********************************************************************
     * AICrawl
     * collide

***********************************************************************/
void ach::AICrawl::collide(ach::PhysLine *line)
{
	if (line->o == ach::Orientation::oVertical)
		dir = !dir;
}



/***********************************************************************
     * AICrawl
     * check

***********************************************************************/
void ach::AICrawl::check()
{
	front = rect_line(owner->phys.rect, dir);

	front.b.y += front.v.y / 2.0f;
	front.calc();

	if (!owner->world->map->collideLine(&front, filterPhysSolid, NULL))
		dir = !dir;
}
