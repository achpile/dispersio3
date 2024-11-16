#ifndef __CHARACTER_PROJECTILE_BASE
#define __CHARACTER_PROJECTILE_BASE


namespace ach
{
	struct Projectile
	{
		ach::ProcessWorld   *world;
		ach::DataProjectile *base;
		ach::Model          *model;
		ach::Tracer         *tracer;
		ach::Line            line;
		ach::Phys            phys;

		sf::Vector2f         last;

		bool  alive;
		bool  flip;
		int   bounces;
		float angle;
		float range;


		 Projectile(ach::ProcessWorld *_world, ach::DataProjectile *_base);
		~Projectile();

		bool update();
		void render();

		void init();
		void hit(sf::Vector2f n);
		void destroy();

		void direction();
		void rotation();
		void explode();

		ach::Tracer *createTracer();
		ach::Impact *createImpact(sf::Vector2f n);
	};
}

#endif
