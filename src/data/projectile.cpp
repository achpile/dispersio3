#include "meta/headers.hpp"


/***********************************************************************
     * DataProjectile
     * constructor

***********************************************************************/
ach::DataProjectile::DataProjectile(json_t *obj)
{
	radius       = json_object_get_branch_real   (obj, "Physics.Radius"  );
	scale        = json_object_get_branch_real   (obj, "Appearance.Scale");
	gravity      = json_object_get_branch_real   (obj, "Physics.Gravity" );
	bounces      = json_object_get_branch_integer(obj, "Physics.Bounces" );
	delay        = json_object_get_branch_real   (obj, "Physics.Delay"   );
	explosive    = json_object_get_branch_boolean(obj, "Explosion.Enable");
	count        = json_object_get_branch_integer(obj, "Explosion.Count" );
	force        = json_object_get_branch_real   (obj, "Explosion.Force" );

	sheet        = db->getSheet(json_object_get_branch_string(obj, "Appearance.Sheet"     ));
	activation   = db->getSound(json_object_get_branch_string(obj, "Appearance.Activation"));
	bump         = db->getSound(json_object_get_branch_string(obj, "Impact.Sound"         ));

	impact       = pair_get_enum(json_object_get_branch_string(obj, "Impact.Type"           ), pairImpact);
	tracer       = pair_get_enum(json_object_get_branch_string(obj, "Tracer.Type"           ), pairTracer);
	orient       = pair_get_enum(json_object_get_branch_string(obj, "Appearance.Orientation"), pairOrient);

	color        = str_to_color(json_object_get_branch_string(obj, "Appearance.Color"));
	colorImpact  = str_to_color(json_object_get_branch_string(obj, "Impact.Color"    ));
	colorTracer  = str_to_color(json_object_get_branch_string(obj, "Tracer.Color"    ));

	strncpy(explosionN, json_object_get_branch_string(obj, "Explosion.Projectile"), STR_LEN_NAME);
}



/***********************************************************************
     * DataProjectile
     * destructor

***********************************************************************/
ach::DataProjectile::~DataProjectile()
{
}



/***********************************************************************
     * DataProjectile
     * finalize

***********************************************************************/
void ach::DataProjectile::finalize()
{
	explosion = db->getProjectile(explosionN);
}
