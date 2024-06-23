#include "meta/headers.hpp"


/***********************************************************************
     * Body
     * constructor

***********************************************************************/
ach::Body::Body(ach::Character *_owner, ach::DataBody*)
{
	owner = _owner;
}



/***********************************************************************
     * Body
     * destructor

***********************************************************************/
ach::Body::~Body()
{
	listDelete(parts);
}



/***********************************************************************
     * Body
     * create

***********************************************************************/
ach::Body* ach::Body::create(ach::Character *_owner, ach::DataBody *_base)
{
	switch (_base->type)
	{
		case ach::BodyType::btNone    : return new ach::Body        (_owner, _base);
		case ach::BodyType::btHumanoid: return new ach::BodyHumanoid(_owner, _base);

		default                       : return new ach::Body        (_owner, _base);
	}
}
