#ifndef __CHARACTER_WEAPON
#define __CHARACTER_WEAPON


namespace ach
{
	struct Weapon
	{
		ach::ProcessWorld *world;
		ach::Character    *owner;
		ach::DataWeapon   *base;
		ach::Timer         cooldown;
		sf::Vector2f       pos;

		float angle;
		float barrel;


		 Weapon(ach::ProcessWorld *_world, ach::Character *_owner, ach::DataWeapon *_base);
		~Weapon();

		void update();

		void aim(sf::Vector2f p, sf::Vector2f v);
		void shot();
	};
}

#endif
