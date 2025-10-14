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
		ach::Timer           delay;
		ach::Line            line;
		ach::Phys            phys;

		sf::Vector2f         last;

		bool  alive;
		bool  flip;
		bool  enemy;
		bool  active;
		int   bounces;
		float angle;


		 Projectile(ach::ProcessWorld *_world, ach::DataProjectile *_base);
		~Projectile();

		bool update();
		void render();

		bool visible();

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
