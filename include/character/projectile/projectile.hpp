#ifndef __CHARACTER_PROJECTILE_PROJECTILE
#define __CHARACTER_PROJECTILE_PROJECTILE


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
		bool  enemy;
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
