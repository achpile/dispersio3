#ifndef __COLLISION_QUADRANT
#define __COLLISION_QUADRANT


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
