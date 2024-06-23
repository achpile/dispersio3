#include "meta/headers.hpp"


/***********************************************************************
     * DataBody
     * constructor

***********************************************************************/
ach::DataBody::DataBody(json_t *obj)
{
	type  = (ach::BodyType)pair_get_enum(json_object_get_string(obj, "Type"), pairBody);
	parts = json_object_get(obj, "Parts");
}



/***********************************************************************
     * DataBody
     * destructor

***********************************************************************/
ach::DataBody::~DataBody()
{
}
