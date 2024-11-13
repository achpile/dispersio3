#ifndef __FRAMEWORK_MENU_CONTROL
#define __FRAMEWORK_MENU_CONTROL


namespace ach
{
	struct MenuItemControl : MenuItem
	{
		ach::ControlAction act;

		bool isBinding;


		 MenuItemControl(ach::Menu *_menu, ach::ControlAction _act);
		~MenuItemControl();

		void render(int i);

		void translate();
		void action();

		void pick();
		void click();

		void bind(sf::Keyboard::Key code);
	};
}

#endif
