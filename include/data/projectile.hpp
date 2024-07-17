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


	enum ImpactType
	{
		itNone = 0,
		itSpark
	};


	enum OrientType
	{
		otNone = 0,
		otDirection,
		otRotation
	};


	struct DataProjectile : DataContent
	{
		ach::DataSheet  *sheet;
		ach::DataSheet  *explosion;
		ach::ImpactType  impact;
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

		bool  explosive;
		bool  gravity;
		int   bounces;


		 DataProjectile(json_t *obj);
		~DataProjectile();
	};
}

#endif
