#ifndef __STATE_GAME
#define __STATE_GAME


namespace ach
{
	struct StateGame : StateBase
	{
		ach::Process *proc;

		 StateGame();
		~StateGame();

		void update();
		void event(sf::Event e);

		void next();
	};
}

#endif
