#include "meta/headers.hpp"


/***********************************************************************
     * DataProjectile
     * constructor

***********************************************************************/
ach::DataProjectile::DataProjectile(json_t *obj)
{
	radius       = json_object_get_branch_real   (obj, "Physics.Radius"  );
	scale        = json_object_get_branch_real   (obj, "Appearance.Scale");
	bounces      = json_object_get_branch_integer(obj, "Physics.Bounces" );
	gravity      = json_object_get_branch_boolean(obj, "Physics.Gravity" );
	explosive    = json_object_get_branch_boolean(obj, "Explosion.Enable");
	explosionR   = json_object_get_branch_real   (obj, "Explosion.Radius");

	sheet        = db->getSheet(json_object_get_branch_string(obj, "Appearance.Sheet"));
	explosion    = db->getSheet(json_object_get_branch_string(obj, "Explosion.Sheet" ));

	sfxBump      = db->getSound(json_object_get_branch_string(obj, "Impact.Sound"   ));
	sfxExplosion = db->getSound(json_object_get_branch_string(obj, "Explosion.Sound"));

	impact       = pair_get_enum(json_object_get_branch_string(obj, "Impact.Type"           ), pairImpact);
	tracer       = pair_get_enum(json_object_get_branch_string(obj, "Tracer.Type"           ), pairTracer);
	orient       = pair_get_enum(json_object_get_branch_string(obj, "Appearance.Orientation"), pairOrient);

	color        = str_to_color(json_object_get_branch_string(obj, "Appearance.Color"));
	colorImpact  = str_to_color(json_object_get_branch_string(obj, "Impact.Color"    ));
	colorTracer  = str_to_color(json_object_get_branch_string(obj, "Tracer.Color"    ));
}



/***********************************************************************
     * DataProjectile
     * destructor

***********************************************************************/
ach::DataProjectile::~DataProjectile()
{
}
