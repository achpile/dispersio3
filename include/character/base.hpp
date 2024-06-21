#ifndef __CHARACTER_BASE
#define __CHARACTER_BASE


namespace ach
{
	struct Character
	{
		std::vector<ach::Model*> models;

		ach::ProcessWorld *world;
		ach::Body         *body;
		ach::Weapon       *weapon;
		ach::Phys          phys;
		sf::Vector2f       aim;

		float speed;
		float jumping;
		bool  dead;


		 Character(ach::ProcessWorld *_world, sf::Vector2f size);
		~Character();

		void update();
		void render();

		void reset();

		void move(int d);
		void jump();
		void shot();
	};
}

#endif
