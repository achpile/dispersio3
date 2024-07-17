#ifndef __DATA_PROJECTILE
#define __DATA_PROJECTILE


namespace ach
{
	enum TracerType
	{
		ttNone = 0,
		ttLine,
		ttSmoke
	};


	enum EffectType
	{
		etNone = 0,
		etSpark
	};


	enum OrientType
	{
		otNone = 0,
		otDirection,
		otRotation
	};


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
		ach::DataSheet  *explosion;
		ach::EffectType  impact;
		ach::TracerType  tracer;
		ach::OrientType  orient;

		sf::SoundBuffer *sfxBump;
		sf::SoundBuffer *sfxExplosion;

		sf::Color        color;
		sf::Color        colorImpact;
		sf::Color        colorTracer;


		float explosionR;
		float radius;
		float scale;

		int   bounces;
		long  flags;


		 DataProjectile(json_t *obj);
		~DataProjectile();
	};
}

#endif
