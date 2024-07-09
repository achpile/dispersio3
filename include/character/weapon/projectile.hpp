#ifndef __CHARACTER_WEAPON_PROJECTILE
#define __CHARACTER_WEAPON_PROJECTILE


namespace ach
{
	struct Projectile
	{
		ach::DataProjectile *base;
		ach::Model          *model;
		ach::Tracer         *tracer;
		ach::Phys            phys;

		bool  alive;
		bool  flip;
		int   bounces;
		float angle;


		 Projectile(ach::DataProjectile *_base, sf::Vector2f pos);
		~Projectile();

		bool update();
		void render();

		void direction();
		void rotation();

		void hit();
	};
}

#endif
