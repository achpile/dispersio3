#ifndef __CHARACTER_WEAPON_PROJECTILE
#define __CHARACTER_WEAPON_PROJECTILE


namespace ach
{
	struct Projectile
	{
		ach::DataProjectile *base;
		ach::Model          *model;
		ach::Phys            phys;

		bool alive;


		 Projectile(ach::DataProjectile *_base);
		~Projectile();

		bool update();
		void render();
	};
}

#endif
