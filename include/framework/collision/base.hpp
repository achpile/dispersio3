#ifndef __FRAMEWORK_COLLISION_BASE
#define __FRAMEWORK_COLLISION_BASE


namespace ach
{
	struct Collision
	{
		std::vector<ach::PhysLine*> lines;


		 Collision();
		~Collision();

		void fill(std::vector<ach::PhysLine*> *list);

		void sort(std::vector<ach::PhysLine*> *list);
		void sort(std::vector<ach::PhysLine*> *list, ach::Line *line);
		void sort(std::vector<ach::PhysLine*> *list, ach::Phys *phys);
	};
}

#endif
