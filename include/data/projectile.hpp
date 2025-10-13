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
		ach::DataProjectile *explosion;
		ach::DataSheet      *sheet;
		ach::DataSound      *bump;
		ach::ImpactType      impact;
		ach::TracerType      tracer;
		ach::OrientType      orient;

		sf::Color color;
		sf::Color colorImpact;
		sf::Color colorTracer;

		float     gravity;
		float     radius;
		float     scale;

		bool      explosive;
		char      explosionN[STR_LEN_NAME];
		int       explosionC;
		int       bounces;


		 DataProjectile(json_t *obj);
		~DataProjectile();

		void finalize();
	};
}

#endif
