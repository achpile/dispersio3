#ifndef __SKEL
#define __SKEL


namespace ach
{
	struct StateMenu : StateBase
	{
		ach::Menu *menu;


		 StateMenu();
		~StateMenu();

		void update();
		void render();
		void event(sf::Event);
	};
}

#endif
