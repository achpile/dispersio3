#ifndef __CHARACTER_CHARACTER
#define __CHARACTER_CHARACTER


namespace ach
{
	struct Character
	{
		ach::ProcessWorld  *world;
		ach::DataCharacter *base;
		ach::AI            *ai;
		ach::Body          *body;
		ach::Weapon        *weapon;
		ach::Phys           phys;
		ach::Timer          spawner;

		sf::Vector2i        dir;
		sf::Vector2f        aim;
		sf::Vector2f        spawn;

		float speed;
		float jumping;
		bool  alive;
		bool  landed;
		bool  enemy;


		 Character(ach::ProcessWorld *_world, ach::DataCharacter *_base, sf::Vector2f _spawn);
		~Character();

		bool update();
		void render();

		bool visible();
		void process();

		void respawn();
		void reset();
		void gateway(sf::FloatRect dest);

		bool hit(ach::Projectile *projectile);
		void die();

		void move(int d);
		void jump();
		void shot();
	};
}

#endif
