#ifndef __FRAMEWORK_GFX_SHEET
#define __FRAMEWORK_GFX_SHEET


namespace ach
{
	enum SheetOrigin
	{
		soNone,
		soCenter,
		soBottom
	};


	struct Sheet
	{
		std::vector<sf::Sprite*> spr;

		sf::Texture  *tex;
		sf::Vector2f  size;

		unsigned int  frames;


		 Sheet(const char *filename, unsigned int _frames, ach::SheetOrigin origin);
		~Sheet();

		sf::Sprite   *getFrame(unsigned int frame);
		sf::Sprite   *getFrameRandom();
		sf::Vector2f  getOrigin(ach::SheetOrigin origin);
	};
}

#endif
