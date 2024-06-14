#ifndef __CHARACTER_PROJECTILE
#define __CHARACTER_PROJECTILE


namespace ach
{
	struct Projectile
	{
		ach::DataProjectile *base;


		 Projectile(ach::DataProjectile *_base);
		~Projectile();

		bool update();
		void render();
	};
}

#endif
