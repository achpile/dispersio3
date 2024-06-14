#ifndef __PROCESS_WORLD
#define __PROCESS_WORLD


namespace ach
{
	struct ProcessWorld : Process
	{
		ach::Map    *map;
		ach::Camera *cam;
		ach::Player *player;

		std::vector<ach::Projectile*> projectiles;


		 ProcessWorld();
		~ProcessWorld();

		void update();
		void render();

		void collision();
	};
}

#endif
