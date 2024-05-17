#ifndef __DATA_WEAPON
#define __DATA_WEAPON


namespace ach
{
	struct DataWeapon
	{
		ach::DataProjectile *projectile;
		sf::SoundBuffer     *shot;

		float cone;
		float cooldown;
		float range;
		float speed;

		char  name[STR_LEN_NAME];
		int   damage;
		int   count;


		 DataWeapon(const char *_name, json_t *obj);
		~DataWeapon();
	};
}

#endif
