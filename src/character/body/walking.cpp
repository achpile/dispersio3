#include "meta/headers.hpp"


/***********************************************************************
     * BodyPlayer
     * constructor

***********************************************************************/
ach::BodyPlayer::BodyPlayer(ach::Character *_owner, ach::DataModel *_base) : Body(_owner, _base)
{
}



/***********************************************************************
     * BodyPlayer
     * destructor

***********************************************************************/
ach::BodyPlayer::~BodyPlayer()
{
}



/***********************************************************************
     * BodyPlayer
     * aim

***********************************************************************/
void ach::BodyPlayer::aim()
{
	barrel = sf::Vector2f(0.0f, 0.0f);
}



/***********************************************************************
     * BodyPlayer
     * animate

***********************************************************************/
void ach::BodyPlayer::animate()
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
     * BodyPlayer
     * flip

***********************************************************************/
void ach::BodyPlayer::flip()
{
	model->scale.x = owner->dir.x;
}



/***********************************************************************
     * BodyPlayer
     * reset

***********************************************************************/
void ach::BodyPlayer::reset()
{
	model->setAnimation("Idle");
}
