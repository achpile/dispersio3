#ifndef __APP
#define __APP

namespace ach {
	struct App {
		sf::RenderWindow *window;

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
