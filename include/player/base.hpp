#ifndef __PLAYER_BASE
#define __PLAYER_BASE


namespace ach
{
	struct Player
	{
		ach::Model *body;
		ach::Model *legs;

		ach::Phys   phys;


		 Player();
		~Player();

		void update();
		void render();
	};
}

#endif
