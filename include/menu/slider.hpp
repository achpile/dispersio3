#ifndef __MENU_SLIDER
#define __MENU_SLIDER


namespace ach
{
	struct MenuItemSlider : MenuItem
	{
		ach::Handler        handler;
		sf::RectangleShape *box;
		sf::RectangleShape *fill;

		json_t *data;

		int     min;
		int     max;
		int     value;

		 MenuItemSlider(ach::Menu *_menu, const char *_name, ach::Handler _handler, json_t *_data, int _min, int _max);
		~MenuItemSlider();

		void style();
		void action(int d);

		void render(int i);
		void finalize();

		void left();
		void right();
		void click();
		void rclick();
	};
}

#endif
