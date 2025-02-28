#include "meta/headers.hpp"


/***********************************************************************
     * DataWeapon
     * constructor

***********************************************************************/
ach::DataWeapon::DataWeapon(json_t *obj)
{
	cone       = json_object_get_real   (obj, "Cone"    );
	speed      = json_object_get_real   (obj, "Speed"   );
	count      = json_object_get_integer(obj, "Count"   );

	shot       = db->getSound(json_object_get_string(obj, "Shot"));
	projectile = db->getProjectile(json_object_get_string(obj, "Projectile"));
}



/***********************************************************************
     * DataWeapon
     * destructor

***********************************************************************/
ach::DataWeapon::~DataWeapon()
{
}
