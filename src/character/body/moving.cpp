#include "meta/headers.hpp"


/***********************************************************************
     * BodyMoving
     * constructor

***********************************************************************/
ach::BodyMoving::BodyMoving(ach::Character *_owner, ach::DataModel *_base) : Body(_owner, _base)
{
}



/***********************************************************************
     * BodyMoving
     * destructor

***********************************************************************/
ach::BodyMoving::~BodyMoving()
{
}



/***********************************************************************
     * BodyMoving
     * animate

***********************************************************************/
void ach::BodyMoving::animate()
{
	if (vector_len(owner->phys.vel) == 0.0f)
		model->setAnimation("Idle");
	else
		model->setAnimation("Moving");
}



/***********************************************************************
     * BodyMoving
     * flip

***********************************************************************/
void ach::BodyMoving::flip()
{
	model->scale.x = owner->dir.x;
}



/***********************************************************************
     * BodyMoving
     * reset

***********************************************************************/
void ach::BodyMoving::reset()
{
	model->setAnimation("Idle");
}
