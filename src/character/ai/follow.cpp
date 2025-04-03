#include "meta/headers.hpp"


/***********************************************************************
     * AIFollow
     * constructor

***********************************************************************/
ach::AIFollow::AIFollow(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
}



/***********************************************************************
     * AIFollow
     * destructor

***********************************************************************/
ach::AIFollow::~AIFollow()
{
}



/***********************************************************************
     * AIFollow
     * control

***********************************************************************/
void ach::AIFollow::control()
{
	search();

	if (target)
	{
		owner->phys.vel = vector_set_len(target->phys.pos - owner->phys.pos, owner->speed);
		owner->dir.x    = math_sign(owner->phys.vel.x);
	}
}
