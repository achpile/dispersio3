#include "meta/headers.hpp"


/***********************************************************************
     * DataProjectile
     * constructor

***********************************************************************/
ach::DataProjectile::DataProjectile(json_t *obj)
{
	radius      = json_object_get_real(obj, "Radius");
	scale       = json_object_get_real(obj, "Scale" );
	explosion   = json_object_get_branch_real(obj, "Explosive.Radius");

	sheet       = db->getSheet(json_object_get_string(obj, "Sheet"));

	color       = str_to_color(json_object_get_string(obj, "Color"));
	colorSparks = str_to_color(json_object_get_branch_string(obj, "Sparks.Color"));
	colorTracer = str_to_color(json_object_get_branch_string(obj, "Tracer.Color"));

	flag_set(&flags, ach::ProjectileFlag::pfBouncy   , json_object_get_boolean(obj, "Bouncy" ));
	flag_set(&flags, ach::ProjectileFlag::pfGravity  , json_object_get_boolean(obj, "Gravity"));

	flag_set(&flags, ach::ProjectileFlag::pfExplosive, json_object_get_branch_boolean(obj, "Explosive.Enable"));
	flag_set(&flags, ach::ProjectileFlag::pfSparks   , json_object_get_branch_boolean(obj, "Sparks.Enable"   ));
	flag_set(&flags, ach::ProjectileFlag::pfTracer   , json_object_get_branch_boolean(obj, "Tracer.Enable"   ));

	sfml_load_sound(&bump, json_object_get_branch_string(obj, "Sound.Bump"));
}



/***********************************************************************
     * DataProjectile
     * destructor

***********************************************************************/
ach::DataProjectile::~DataProjectile()
{
	delete bump;
}
