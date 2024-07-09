#ifndef __DATA_PROJECTILE
#define __DATA_PROJECTILE


namespace ach
{
	enum ProjectileFlag
	{
		pfExplosive = 1 << 0,
		pfGravity   = 1 << 1,
		pfDirection = 1 << 2,
		pfRotation  = 1 << 3
	};


	struct DataProjectile : DataContent
	{
		ach::DataSheet  *sheet;
		ach::EffectType  impact;
		ach::TracerType  tracer;

		sf::SoundBuffer *bump;

		sf::Color        color;
		sf::Color        colorImpact;
		sf::Color        colorTracer;


		float explosion;
		float radius;
		float scale;

		int   bounces;
		long  flags;


		 DataProjectile(json_t *obj);
		~DataProjectile();
	};
}

#endif
