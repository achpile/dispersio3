#include "meta/headers.hpp"


/***********************************************************************
     * DataBoss
     * constructor

***********************************************************************/
ach::DataBoss::DataBoss(json_t *obj)
{
	type       = pair_get_enum(json_object_get_branch_string(obj, "Type"), pairBoss);

	model      = json_object_get(obj, "Model"     );
	projectile = json_object_get(obj, "Projectile");
	summon     = json_object_get(obj, "Summon"    );
}



/***********************************************************************
     * DataBoss
     * destructor

***********************************************************************/
ach::DataBoss::~DataBoss()
{
}
