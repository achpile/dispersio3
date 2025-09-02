#ifndef __GUI_LEVEL
#define __GUI_LEVEL


namespace ach
{
	struct LevelSelect
	{
		ach::RectangleShape *box;
		ach::RectangleShape *preview;
		ach::Menu           *menu;


		 LevelSelect();
		~LevelSelect();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void controls();

		void fill();
	};
}

#endif
