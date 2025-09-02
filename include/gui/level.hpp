#ifndef __GUI_LEVEL
#define __GUI_LEVEL


namespace ach
{
	struct LevelSelect
	{
		std::vector<ach::Statistic*> lines;

		ach::RectangleShape         *box;
		ach::RectangleShape         *preview;

		ach::DataMap                *selected;
		ach::Text                   *text;
		ach::Menu                   *menu;
		ach::Handler                 handler;
		ach::LevelMode               mode;

		sf::Vector2f                 pos;

		bool   active;
		void  *context;
		float  width;
		float  spacing;


		 LevelSelect(void *_context, ach::Handler _handler);
		~LevelSelect();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void controls();
		void stats();
		void pick(json_t *data);

		void init(ach::LevelMode _mode);
		void fill(const char *name, json_t *list);
	};
}

#endif
