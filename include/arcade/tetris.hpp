#ifndef __ARCADE_TETRIS
#define __ARCADE_TETRIS


namespace ach
{
	struct ArcadeTetris : Arcade
	{
		 ArcadeTetris(sf::String _caption);
		~ArcadeTetris();

		void process();
		void draw();
		void handle();
	};
}

#endif
