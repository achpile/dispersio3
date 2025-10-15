#include "meta/headers.hpp"


/***********************************************************************
     * DataBoss
     * constructor

***********************************************************************/
ach::DataBoss::DataBoss(json_t *obj)
{
	type   = pair_get_enum(json_object_get_branch_string(obj, "Type"), pairBoss);

	gfx    = json_object_get(obj, "GFX"   );
	sfx    = json_object_get(obj, "SFX"   );
	model  = json_object_get(obj, "Model" );
	weapon = json_object_get(obj, "Weapon");
}



/***********************************************************************
     * DataBoss
     * destructor

***********************************************************************/
ach::DataBoss::~DataBoss()
{
}
