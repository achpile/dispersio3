#ifndef __FRAMEWORK_COLLISION_BASE
#define __FRAMEWORK_COLLISION_BASE


namespace ach
{
	struct Collision
	{
		std::vector<ach::PhysLine*> lines;


		 Collision();
		~Collision();

		void collide(ach::Phys *phys);
		void collideLines(ach::Phys *phys);
		bool collideLine(ach::Phys *phys, ach::PhysLine *line);
	};
}

#endif
