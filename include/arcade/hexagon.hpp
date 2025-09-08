#ifndef __ARCADE_HEXAGON
#define __ARCADE_HEXAGON


namespace ach
{
	struct ArcadeHexagon : Arcade
	{
		 ArcadeHexagon(bool select);
		~ArcadeHexagon();

		void prepare();
		void process();
		void draw();
		void handle();
	};
}

#endif
