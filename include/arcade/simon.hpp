#ifndef __ARCADE_SIMON
#define __ARCADE_SIMON


namespace ach
{
	struct ArcadeSimon : Arcade
	{
		 ArcadeSimon(bool select);
		~ArcadeSimon();

		void prepare();
		void process();
		void draw();
		void handle();
	};
}

#endif
