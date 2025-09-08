#ifndef __GUI_CABINET
#define __GUI_CABINET


namespace ach
{
	struct Cabinet
	{
		ach::Arcade *game;
		ach::Sprite *cabinet;


		 Cabinet();
		~Cabinet();

		void update();
		void render();

		void init();
		bool active();
	};
}

#endif
