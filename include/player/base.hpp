#ifndef __PLAYER_BASE
#define __PLAYER_BASE


namespace ach
{
	struct Player
	{
		ach::Character *character;


		 Player(ach::ProcessWorld *world);
		~Player();

		void update();
		void render();

		void controls();
		void aim();

		void respawn(sf::Vector2f spawn);
		void move(int d, bool hold);
	};
}

#endif
