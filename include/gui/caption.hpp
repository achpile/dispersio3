#ifndef __GUI_CAPTION
#define __GUI_CAPTION


namespace ach
{
	struct Caption
	{
		ach::Timer         fader;

		sf::RenderTexture *tex;
		sf::Sprite        *spr;


		 Caption(sf::String _caption);
		~Caption();

		void update();
		void render();
	};
}

#endif
