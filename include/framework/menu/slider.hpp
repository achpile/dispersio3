#ifndef __FRAMEWORK_MENU_SLIDER
#define __FRAMEWORK_MENU_SLIDER


namespace ach
{
	struct MenuItemSlider : MenuItem
	{
		sf::RectangleShape *box;
		sf::RectangleShape *fill;

		int min;
		int max;
		int value;

		 MenuItemSlider(ach::Menu *_menu, const char *_name, int _min, int _max);
		~MenuItemSlider();

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
