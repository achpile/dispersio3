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
	explosionR  = json_object_get_branch_real(obj, "Explosion.Radius");

	sheet       = db->getSheet(json_object_get_string(obj, "Sheet"));
	explosion   = db->getSheet(json_object_get_branch_string(obj, "Explosion.Sheet"));

	impact      = (ach::EffectType)pair_get_enum(json_object_get_branch_string(obj, "Impact.Type"), pairEffect);
	tracer      = (ach::TracerType)pair_get_enum(json_object_get_branch_string(obj, "Tracer.Type"), pairTracer);

	color       = str_to_color(json_object_get_string(obj, "Color"));
	colorImpact = str_to_color(json_object_get_branch_string(obj, "Impact.Color"));
	colorTracer = str_to_color(json_object_get_branch_string(obj, "Tracer.Color"));

	flag_set(&flags, ach::ProjectileFlag::pfGravity  , json_object_get_boolean(obj, "Gravity"  ));
	flag_set(&flags, ach::ProjectileFlag::pfDirection, json_object_get_boolean(obj, "Direction"));
	flag_set(&flags, ach::ProjectileFlag::pfRotation , json_object_get_boolean(obj, "Rotation" ));

	flag_set(&flags, ach::ProjectileFlag::pfExplosive, json_object_get_branch_boolean(obj, "Explosion.Enable"));

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
