#include "meta/headers.hpp"


/***********************************************************************
     * Datamodel
     * constructor

***********************************************************************/
ach::Datamodel::Datamodel()
{
	dm   = json_preprocess_include("dm.json", "data/dm");
	data = json_dm_generate_default(NULL, dm);

	load();
}



/***********************************************************************
     * Datamodel
     * destructor

***********************************************************************/
ach::Datamodel::~Datamodel()
{
	json_decref(data);
	json_decref(dm);
}



/***********************************************************************
     * Datamodel
     * load

***********************************************************************/
void ach::Datamodel::load()
{
}
