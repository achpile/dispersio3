#ifndef __PROCESS_WORLD
#define __PROCESS_WORLD


namespace ach
{
	struct ProcessWorld : Process
	{
		 ProcessWorld();
		~ProcessWorld();

		void update();
		void render();
	};
}

#endif
