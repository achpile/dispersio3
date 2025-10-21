#ifndef __GUI_ACHIEVEMENTS
#define __GUI_ACHIEVEMENTS


namespace ach
{
	struct Achievements
	{
		bool active;


		 Achievements();
		~Achievements();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void controls();
		void init();
	};
}

#endif
