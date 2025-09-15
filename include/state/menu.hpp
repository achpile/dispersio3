#ifndef __STATE_MENU
#define __STATE_MENU


namespace ach
{
	enum MenuState
	{
		msMain,
		msTraining
	};


	struct StateMenu : StateBase
	{
		ach::Menu        *menu;
		ach::Sprite      *logo;
		ach::LevelSelect *training;
		ach::MenuState    state;


		 StateMenu();
		~StateMenu();

		void update();
		void render();
		void event(sf::Event e);

		void translate();
		void style();

		void prepare();
		void finalize();
		void draw();

		void fill();
	};
}

#endif
