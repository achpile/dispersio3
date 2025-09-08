#ifndef __ARCADE_TETRIS
#define __ARCADE_TETRIS


namespace ach
{
	struct ArcadeTetris : Arcade
	{
		 ArcadeTetris(bool select);
		~ArcadeTetris();

		void prepare();
		void process();
		void draw();
		void handle();
	};
}

#endif
