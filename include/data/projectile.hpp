#ifndef __DATA_PROJECTILE
#define __DATA_PROJECTILE


namespace ach
{
	enum ProjectileFlag
	{
		pfBouncy    = 1 << 0,
		pfExplosive = 1 << 1,
		pfGravity   = 1 << 2,
		pfSparks    = 1 << 3,
		pfTracer    = 1 << 4
	};


	struct DataProjectile : DataContent
	{
		ach::DataSheet  *sheet;
		sf::SoundBuffer *bump;

		sf::Color        color;
		sf::Color        colorSparks;
		sf::Color        colorTracer;

		float explosion;
		float radius;
		float scale;

		long  flags;


		 DataProjectile(json_t *obj);
		~DataProjectile();
	};
}

#endif
