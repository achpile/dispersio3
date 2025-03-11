#ifndef __PROCESS_WORLD
#define __PROCESS_WORLD


namespace ach
{
	struct ProcessWorld : Process
	{
		ach::Map       *map;
		ach::Character *player;


		 ProcessWorld(ach::StateGame *_owner);
		~ProcessWorld();

		void update();
		void render();

		void gateway(sf::FloatRect dest);
		void goal();
	};
}

#endif
