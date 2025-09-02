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
		ach::Handler         handler;

		bool  active;
		void *context;


		 LevelSelect(void *_context, ach::Handler _handler);
		~LevelSelect();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void controls();
		void pick(json_t *data);

		void init(ach::LevelMode type);
		void fill(ach::LevelMode type, const char *name, json_t *list);
	};
}

#endif
