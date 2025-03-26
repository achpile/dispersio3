#include "meta/headers.hpp"


/***********************************************************************
     * BodyJumper
     * constructor

***********************************************************************/
ach::BodyJumper::BodyJumper(ach::Character *_owner, ach::DataModel *_base) : Body(_owner, _base)
{
}



/***********************************************************************
     * BodyJumper
     * destructor

***********************************************************************/
ach::BodyJumper::~BodyJumper()
{
}



/***********************************************************************
     * BodyJumper
     * animate

***********************************************************************/
void ach::BodyJumper::animate()
{
	if (!owner->phys.grounded)
	{
		if (owner->phys.vel.y > 0.0f)
			model->setAnimation("Fall");
		else
			model->setAnimation("Jump");
	}
	else
		model->setAnimation("Idle");
}



/***********************************************************************
     * BodyJumper
     * flip

***********************************************************************/
void ach::BodyJumper::flip()
{
	model->scale.x = owner->dir.x;
}



/***********************************************************************
     * BodyJumper
     * reset

***********************************************************************/
void ach::BodyJumper::reset()
{
	model->setAnimation("Idle");
}
