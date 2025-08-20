#include "meta/headers.hpp"


/***********************************************************************
     * BodySniper
     * constructor

***********************************************************************/
ach::BodySniper::BodySniper(ach::Character *_owner, ach::DataModel *_base) : Body(_owner, _base)
{
}



/***********************************************************************
     * BodySniper
     * destructor

***********************************************************************/
ach::BodySniper::~BodySniper()
{
}



/***********************************************************************
     * BodySniper
     * animate

***********************************************************************/
void ach::BodySniper::animate()
{
	     if (owner->aim.y < -0.90f)  model->setAnimation("Up"         );
	else if (owner->aim.y < -0.38f) model->setAnimation("DiagonalUp"  );
	else if (owner->aim.y <  0.38f) model->setAnimation("Front"       );
	else if (owner->aim.y <  0.90f) model->setAnimation("DiagonalDown");
	else                            model->setAnimation("Down"        );
}



/***********************************************************************
     * BodySniper
     * flip

***********************************************************************/
void ach::BodySniper::flip()
{
	model->scale.x = owner->dir.x;
}



/***********************************************************************
     * BodySniper
     * reset

***********************************************************************/
void ach::BodySniper::reset()
{
	model->setAnimation("Front");
}
