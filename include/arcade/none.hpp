#ifndef __ARCADE_NONE
#define __ARCADE_NONE


namespace ach
{
	struct ArcadeNone : Arcade
	{
		 ArcadeNone(bool select);
		~ArcadeNone();

		void prepare();
	};
}

#endif
