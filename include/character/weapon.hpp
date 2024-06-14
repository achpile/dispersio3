#ifndef __CHARACTER_WEAPON
#define __CHARACTER_WEAPON


namespace ach
{
	struct Weapon
	{
		ach::ProcessWorld *world;
		ach::DataWeapon   *base;
		ach::Timer         cooldown;
		sf::Vector2f       aim;
		sf::Vector2f       pos;

		float angle;


		 Weapon(ach::ProcessWorld *_world, ach::DataWeapon *_base);
		~Weapon();

		void update();

		void shot();
	};
}

#endif
