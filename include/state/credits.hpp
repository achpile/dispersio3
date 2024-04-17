#ifndef __STATE_CREDITS
#define __STATE_CREDITS


namespace ach
{
	struct StateCredits : StateBase
	{
		 StateCredits();
		~StateCredits();

		void update();
		void render();
		void event(sf::Event);
	};
}

#endif
