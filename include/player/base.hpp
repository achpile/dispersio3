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


		 Player();
		~Player();

		void update();
		void render();

		void reset();
		void respawn(sf::Vector2f spawn);
	};
}

#endif
