#ifndef __MAP_SELECTOR
#define __MAP_SELECTOR


namespace ach
{
	struct Selector
	{
		ach::MapObject *object;
		ach::Sprite    *corner;


		 Selector();
		~Selector();

		void update();
		void render();
	};
}

#endif
