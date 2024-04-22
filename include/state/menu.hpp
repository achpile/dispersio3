#ifndef __SKEL
#define __SKEL


namespace ach
{
	struct StateMenu : StateBase
	{
		ach::Menu   *menu;
		ach::Sprite *logo;


		 StateMenu();
		~StateMenu();

		void update();
		void render();
		void event(sf::Event e);

		void translate();

		void hover(sf::Vector2f pos);
		void click(sf::Vector2f pos, bool left);

		void fill();
	};
}

#endif
