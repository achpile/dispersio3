#ifndef __MAP_CAPTION
#define __MAP_CAPTION


namespace ach
{
	struct MapCaption
	{
		sf::String caption;


		 MapCaption(sf::String _caption);
		~MapCaption();

		void update();
		void render();
	};
}

#endif
