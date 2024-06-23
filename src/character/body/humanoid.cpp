#include "meta/headers.hpp"


/***********************************************************************
     * BodyHumanoid
     * constructor

***********************************************************************/
ach::BodyHumanoid::BodyHumanoid(ach::Character *_owner, ach::DataBody *_base) : Body(_owner, _base)
{
	legs = new ach::BodyPart(json_object_get(_base->parts, "Legs"));
	body = new ach::BodyPart(json_object_get(_base->parts, "Body"));

	parts.push_back(legs);
	parts.push_back(body);
}



/***********************************************************************
     * BodyHumanoid
     * destructor

***********************************************************************/
ach::BodyHumanoid::~BodyHumanoid()
{
}



/***********************************************************************
     * BodyHumanoid
     * animate

***********************************************************************/
void ach::BodyHumanoid::animate()
{
	if (owner->phys.grounded)
	{
		if (owner->phys.moving)
			legs->setAnimation("Walk");
		else
			legs->setAnimation("Idle");
	}
	else
	{
		if (owner->phys.vel.y > 0.0f)
			legs->setAnimation("Fall");
		else
			legs->setAnimation("Jump");
	}


	if (owner->dir.y == 0)
	{
		body->setAnimation("Front");
	}
	else if (owner->dir.y == 1)
	{
		body->setAnimation("DiagonalDown");
	}
	else
	{
		if (owner->phys.moving)
			body->setAnimation("DiagonalUp");
		else
			body->setAnimation("Up");
	}


	legs->model->scale.x = owner->dir.x;
	body->model->scale.x = owner->dir.x;
}



/***********************************************************************
     * BodyHumanoid
     * reset

***********************************************************************/
void ach::BodyHumanoid::reset()
{
	legs->setAnimation("Idle");
	body->setAnimation("Front");
}
