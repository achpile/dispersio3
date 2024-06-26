#ifndef __CHARACTER_BASE
#define __CHARACTER_BASE


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

		sf::Vector2i        dir;
		sf::Vector2f        aim;

		float speed;
		float jumping;
		bool  dead;
		bool  landed;


		 Character(ach::ProcessWorld *_world, ach::DataCharacter *_base);
		~Character();

		bool update();
		void render();

		void process();

		void respawn(sf::Vector2f spawn);
		void reset();

		void move(int d);
		void jump();
		void shot();
	};
}

#endif
