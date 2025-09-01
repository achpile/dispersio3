#ifndef __PROCESS_WORLD
#define __PROCESS_WORLD


namespace ach
{
	enum WorldState
	{
		wsFadeIn,
		wsFadeOut,
		wsMessage,
		wsPause,
		wsGame
	};


	struct ProcessWorld : Process
	{
		ach::Map        *map;
		ach::Character  *player;
		ach::Message    *message;
		ach::Menu       *menu;

		ach::WorldState  state;
		ach::Timer       fader;


		 ProcessWorld(ach::StateGame *_owner, ach::DataMap *_map);
		~ProcessWorld();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void prepare();
		void finalize();
		void fill();

		void gateway(sf::FloatRect dest);
		void goal();
		void pause();
	};
}

#endif
