#ifndef __PLAYER_BASE
#define __PLAYER_BASE


namespace ach
{
	struct Player
	{
		ach::Character *character;

		ach::Model     *body;
		ach::Model     *legs;

		sf::Vector2i    dir;


		 Player(ach::ProcessWorld *world);
		~Player();

		void update();
		void render();

		void controls();
		void animate();

		void reset();
		void respawn(sf::Vector2f spawn);

		void move(int d);
	};
}

#endif
