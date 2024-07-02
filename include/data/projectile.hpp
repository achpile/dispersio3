#ifndef __DATA_PROJECTILE
#define __DATA_PROJECTILE


namespace ach
{
	enum ProjectileFlag
	{
		pfBouncy    = 1 << 0,
		pfExplosive = 1 << 1,
		pfGravity   = 1 << 2
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

		long  flags;


		 DataProjectile(json_t *obj);
		~DataProjectile();
	};
}

#endif
