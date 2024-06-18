#ifndef __CHARACTER_PROJECTILE
#define __CHARACTER_PROJECTILE


namespace ach
{
	struct Projectile
	{
		ach::DataProjectile *base;
		ach::Sheet          *sheet;
		ach::Animation       anim;
		ach::Phys            phys;

		sf::Vector2f         scale;

		bool alive;


		 Projectile(ach::DataProjectile *_base);
		~Projectile();

		bool update();
		void render();
	};
}

#endif
