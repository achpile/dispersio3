#ifndef __FRAMEWORK_COLLISION_BASE
#define __FRAMEWORK_COLLISION_BASE


namespace ach
{
	struct Collision
	{
		std::vector<ach::PhysLine*> lines;


		 Collision();
		~Collision();
	};
}

#endif
