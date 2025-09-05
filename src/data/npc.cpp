#include "meta/headers.hpp"


/***********************************************************************
     * DataNPC
     * constructor

***********************************************************************/
ach::DataNPC::DataNPC(json_t *obj)
{
	model  = db->getModel(json_object_get_string(obj, "Model"));
	wander = json_object_get_boolean(obj, "Wander");
	speech = json_object_get(obj, "Speech");
}



/***********************************************************************
     * DataNPC
     * destructor

***********************************************************************/
ach::DataNPC::~DataNPC()
{
}
