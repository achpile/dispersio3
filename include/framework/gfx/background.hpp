#ifndef __FRAMEWORK_GFX_BACKGROUND
#define __FRAMEWORK_GFX_BACKGROUND


namespace ach
{
	struct Background
	{
		ach::Sprite  *spr;
		sf::Vector2i  size;
		sf::Vector2i  rect;

		float scale;
		float factor;


		 Background(const char *filename, float _factor);
		~Background();

		void render(float offset);

		void setSize(int width, int height);
	};
}

#endif
