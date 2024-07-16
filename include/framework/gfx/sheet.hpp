#ifndef __FRAMEWORK_GFX_SHEET
#define __FRAMEWORK_GFX_SHEET


namespace ach
{
	struct Sheet
	{
		std::vector<sf::Sprite*> spr;

		sf::Texture  *tex;
		sf::Vector2f  size;

		unsigned int  frames;


		 Sheet(const char *filename, unsigned int _frames, bool centered);
		~Sheet();

		sf::Sprite *getFrame(unsigned int frame);
	};
}

#endif
