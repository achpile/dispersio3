#include "meta/headers.hpp"


/***********************************************************************
     * DataWeapon
     * constructor

***********************************************************************/
ach::DataWeapon::DataWeapon(json_t *obj)
{
	cone       = json_object_get_real(obj, "Cone"    );
	cooldown   = json_object_get_real(obj, "Cooldown");
	range      = json_object_get_real(obj, "Range"   );
	speed      = json_object_get_real(obj, "Speed"   );

	damage     = json_object_get_integer(obj, "Damage");
	count      = json_object_get_integer(obj, "Count" );

	projectile = db->getProjectile(json_object_get_string(obj, "Projectile"));

	sfml_load_sound(&shot, json_object_get_string(obj, "Shot"));
}



/***********************************************************************
     * DataWeapon
     * destructor

***********************************************************************/
ach::DataWeapon::~DataWeapon()
{
	delete shot;
}
