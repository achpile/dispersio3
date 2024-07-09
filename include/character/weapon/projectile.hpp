#ifndef __CHARACTER_WEAPON_PROJECTILE
#define __CHARACTER_WEAPON_PROJECTILE


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


		 Projectile(ach::ProcessWorld *_world, ach::DataProjectile *_base, sf::Vector2f pos);
		~Projectile();

		bool update();
		void render();

		void hit(sf::Vector2f c, sf::Vector2f n);

		void direction();
		void rotation();
	};
}

#endif
