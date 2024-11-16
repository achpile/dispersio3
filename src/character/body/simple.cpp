#include "meta/headers.hpp"


/***********************************************************************
     * BodySimple
     * constructor

***********************************************************************/
ach::BodySimple::BodySimple(ach::Character *_owner, ach::DataBody *_base) : Body(_owner, _base)
{
	body = new ach::BodyPart(json_object_get(_base->parts, "Body"));

	parts.push_back(body);
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
	body->setAnimation("Idle");
}
