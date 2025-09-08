#ifndef __ARCADE_BRICKOUT
#define __ARCADE_BRICKOUT


namespace ach
{
	struct ArcadeBrickOut : Arcade
	{
		 ArcadeBrickOut(sf::String _caption);
		~ArcadeBrickOut();

		void process();
		void draw();
		void handle();
	};
}

#endif
