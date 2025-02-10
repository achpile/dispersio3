#include "meta/headers.hpp"


/***********************************************************************
     * BodySimple
     * constructor

***********************************************************************/
ach::BodySimple::BodySimple(ach::Character *_owner, ach::DataModel *_base) : Body(_owner, _base)
{
}



/***********************************************************************
     * BodySimple
     * destructor

***********************************************************************/
ach::BodySimple::~BodySimple()
{
}



/***********************************************************************
     * BodySimple
     * reset

***********************************************************************/
void ach::BodySimple::reset()
{
	model->setAnimation("Idle");
}
