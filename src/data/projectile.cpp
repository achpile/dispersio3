#include "meta/headers.hpp"


/***********************************************************************
     * DataProjectile
     * constructor

***********************************************************************/
ach::DataProjectile::DataProjectile(json_t *obj)
{
	radius      = json_object_get_real   (obj, "Radius" );
	scale       = json_object_get_real   (obj, "Scale"  );
	bounces     = json_object_get_integer(obj, "Bounces");
	gravity     = json_object_get_boolean(obj, "Gravity");
	explosive   = json_object_get_branch_boolean(obj, "Explosion.Enable");
	explosionR  = json_object_get_branch_real   (obj, "Explosion.Radius");

	sheet       = db->getSheet(json_object_get_string(obj, "Sheet"));
	explosion   = db->getSheet(json_object_get_branch_string(obj, "Explosion.Sheet"));

	impact      = (ach::ImpactType)pair_get_enum(json_object_get_branch_string(obj, "Impact.Type"), pairImpact);
	tracer      = (ach::TracerType)pair_get_enum(json_object_get_branch_string(obj, "Tracer.Type"), pairTracer);
	orient      = (ach::OrientType)pair_get_enum(json_object_get_string       (obj, "Orientation"), pairOrient);

	color       = str_to_color(json_object_get_string(obj, "Color"));
	colorImpact = str_to_color(json_object_get_branch_string(obj, "Impact.Color"));
	colorTracer = str_to_color(json_object_get_branch_string(obj, "Tracer.Color"));

	sfml_load_sound(&sfxBump     , json_object_get_branch_string(obj, "Impact.Sound"   ));
	sfml_load_sound(&sfxExplosion, json_object_get_branch_string(obj, "Explosion.Sound"));
}



/***********************************************************************
     * DataProjectile
     * destructor

***********************************************************************/
ach::DataProjectile::~DataProjectile()
{
	delete sfxBump;
	delete sfxExplosion;
}
