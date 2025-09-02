#ifndef __GUI_LEVEL
#define __GUI_LEVEL


namespace ach
{
	struct LevelSelect
	{
		ach::RectangleShape *box;
		ach::RectangleShape *preview;

		ach::DataMap        *selected;
		ach::Text           *text;
		ach::Menu           *menu;

		bool active;


		 LevelSelect();
		~LevelSelect();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void controls();

		void init(const char *name, ach::Handler handler, ach::LevelList type);
		void fill(const char *name, ach::Handler handler, json_t *list);
	};
}

#endif
