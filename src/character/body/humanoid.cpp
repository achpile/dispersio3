#include "meta/headers.hpp"


/***********************************************************************
     * BodyHumanoid
     * constructor

***********************************************************************/
ach::BodyHumanoid::BodyHumanoid(ach::Character *_owner, ach::DataBody *_base) : Body(_owner, _base)
{
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
