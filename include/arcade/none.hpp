#ifndef __ARCADE_NONE
#define __ARCADE_NONE


namespace ach
{
	struct ArcadeNone : Arcade
	{
		 ArcadeNone(sf::String _caption);
		~ArcadeNone();

		void prepare();
	};
}

#endif
