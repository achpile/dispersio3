#ifndef __FRAMEWORK_GFX_BACKGROUND
#define __FRAMEWORK_GFX_BACKGROUND


namespace ach
{
	struct Background
	{
		ach::Sprite *spr;

		float factor;


		 Background(const char *filename, float _factor);
		~Background();
	};
}

#endif
