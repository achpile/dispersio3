#ifndef __MAP_CAPTION
#define __MAP_CAPTION


namespace ach
{
	struct MapCaption
	{
		ach::Timer         fader;

		sf::RenderTexture *tex;
		sf::Sprite        *spr;


		 MapCaption(sf::String _caption);
		~MapCaption();

		void update();
		void render();
	};
}

#endif
