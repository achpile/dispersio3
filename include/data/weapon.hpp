#ifndef __DATA_WEAPON
#define __DATA_WEAPON


namespace ach
{
	struct DataWeapon : DataContent
	{
		ach::DataProjectile *projectile;
		ach::DataSound      *shot;

		float cone;
		float speed;
		int   count;


		 DataWeapon(json_t *obj);
		~DataWeapon();
	};
}

#endif
