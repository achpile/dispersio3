#ifndef __MAP_PARALLAX
#define __MAP_PARALLAX


namespace ach
{
	struct Parallax
	{
		ach::DataParallax *base;


		 Parallax(ach::DataParallax *_base);
		~Parallax();

		void render(float offset);
	};
}

#endif
