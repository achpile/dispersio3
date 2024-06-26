#ifndef __META_APP
#define __META_APP

namespace ach
{
	struct App
	{
		ach::StateBase     *state;
		sf::RenderWindow   *window;

		ach::GameState      stateCurr;
		ach::GameState      stateNext;

		bool isRunning;
		bool isFocused;


		 App();
		~App();

		void update();
		void create();
		void resize();
		void events();
		void event(sf::Event e);

		void stateSet(ach::GameState s);
		void stateSwitch();

		void mouse(bool visible);
	};
}

#endif
