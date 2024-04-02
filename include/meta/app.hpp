#ifndef __META_APP
#define __META_APP

namespace ach
{
	struct App
	{
		ach::RenderManager *rm;
		ach::TimeManager   *tm;

		ach::StateBase     *state;
		sf::RenderWindow   *window;

		bool isRunning;
		bool isFocused;


		 App();
		~App();

		void update();
		void create();
		void resize();
		void events();
		void event(sf::Event e);
	};
}

#endif
