#ifndef __FRAMEWORK_GFX_SPRITE
#define __FRAMEWORK_GFX_SPRITE


namespace ach
{
	struct Sprite
	{
		sf::Texture  *tex;
		sf::Sprite   *spr;
		sf::Vector2f  size;


		 Sprite(const char *filename, bool repeated, bool centered);
		~Sprite();
	};
}

#endif
