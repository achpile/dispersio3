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

		bool  alive;
		bool  flip;
		int   bounces;
		float angle;
		float range;


		 Projectile(ach::ProcessWorld *_world, ach::DataProjectile *_base, sf::Vector2f pos);
		~Projectile();

		bool update();
		void render();

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
