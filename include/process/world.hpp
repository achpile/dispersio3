#ifndef __PROCESS_WORLD
#define __PROCESS_WORLD


namespace ach
{
	enum WorldState
	{
		wsFadeIn,
		wsFadeOut,
		wsGame
	};


	struct ProcessWorld : Process
	{
		ach::Map        *map;
		ach::Character  *player;

		ach::WorldState  state;
		ach::Timer       fader;


		 ProcessWorld(ach::StateGame *_owner, ach::DataMap *_map);
		~ProcessWorld();

		void update();
		void render();

		void prepare();
		void finalize();

		void gateway(sf::FloatRect dest);
		void goal();
	};
}

#endif
