#ifndef __ARCADE_SNAKE
#define __ARCADE_SNAKE


namespace ach
{
	struct ArcadeSnake : Arcade
	{
		 ArcadeSnake(sf::String _caption);
		~ArcadeSnake();

		void prepare();
		void process();
		void draw();
		void handle();
	};
}

#endif
