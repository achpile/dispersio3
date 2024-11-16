#ifndef __FRAMEWORK_COLLISION_QUADRANT
#define __FRAMEWORK_COLLISION_QUADRANT


namespace ach
{
	struct Quadrant
	{
		std::vector<ach::PhysLine*> lines;


		 Quadrant();
		~Quadrant();

		void fill(std::vector<ach::PhysLine*> *list);
	};
}

#endif
