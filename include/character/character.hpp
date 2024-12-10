#ifndef __CHARACTER_CHARACTER
#define __CHARACTER_CHARACTER


namespace ach
{
	struct Character
	{
		std::vector<ach::Model*> models;

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
		int   health;
		bool  alive;
		bool  landed;
		bool  enemy;
		bool  respawning;


		 Character(ach::ProcessWorld *_world, ach::DataCharacter *_base, sf::Vector2f _spawn);
		~Character();

		bool update();
		void render();

		void process();

		void respawn();
		void reset();
		void gateway(sf::FloatRect dest);

		bool hit(ach::Projectile *projectile);
		void damage(int damage, sf::Vector2f c, sf::Vector2f n);
		void die(sf::Vector2f c, sf::Vector2f n);
		void explode(sf::Vector2f c, sf::Vector2f n);
		void chunk(sf::Vector2f pos, sf::Vector2f vel);

		void move(int d);
		void jump();
		void shot();
	};
}

#endif
