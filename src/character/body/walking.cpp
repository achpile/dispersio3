#include "meta/headers.hpp"


/***********************************************************************
     * BodyWalking
     * constructor

***********************************************************************/
ach::BodyWalking::BodyWalking(ach::Character *_owner, ach::DataModel *_base) : Body(_owner, _base)
{
}



/***********************************************************************
     * BodyWalking
     * destructor

***********************************************************************/
ach::BodyWalking::~BodyWalking()
{
}



/***********************************************************************
     * BodyWalking
     * aim

***********************************************************************/
void ach::BodyWalking::aim()
{
	barrel = sf::Vector2f(0.0f, 0.0f);
}



/***********************************************************************
     * BodyWalking
     * animate

***********************************************************************/
void ach::BodyWalking::animate()
{
	if (owner->phys.grounded)
	{
		if (owner->phys.moving)
			model->setAnimation("Walk");
		else
			model->setAnimation("Idle");
	}
	else
	{
		if (owner->phys.vel.y > 0.0f)
			model->setAnimation("Fall");
		else
			model->setAnimation("Jump");
	}
}



/***********************************************************************
     * BodyWalking
     * flip

***********************************************************************/
void ach::BodyWalking::flip()
{
	model->scale.x = owner->dir.x;
}



/***********************************************************************
     * BodyWalking
     * reset

***********************************************************************/
void ach::BodyWalking::reset()
{
	model->setAnimation("Idle");
}
