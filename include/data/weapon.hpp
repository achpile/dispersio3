#ifndef __DATA_WEAPON
#define __DATA_WEAPON


namespace ach
{
	struct DataWeapon : DataContent
	{
		ach::DataProjectile *projectile;
		sf::SoundBuffer     *shot;

		float cone;
		float cooldown;
		float range;
		float speed;
		int   count;


		 DataWeapon(json_t *obj);
		~DataWeapon();
	};
}

#endif
