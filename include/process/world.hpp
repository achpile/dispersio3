#ifndef __PROCESS_WORLD
#define __PROCESS_WORLD


namespace ach
{
	struct ProcessWorld : Process
	{
		std::vector<ach::Effect*> gfx;

		ach::Map       *map;
		ach::Camera    *cam;
		ach::Character *player;


		 ProcessWorld();
		~ProcessWorld();

		void update();
		void render();
	};
}

#endif
