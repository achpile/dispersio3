#ifndef __FRAMEWORK_COLLISION_BASE
#define __FRAMEWORK_COLLISION_BASE


namespace ach
{
	struct Collision
	{
		std::vector<ach::PhysLine*> lines;

		ach::Quadrant ***quad;
		sf::Vector2i     size;
		sf::Vector2i     area;


		 Collision();
		~Collision();

		void split(sf::Vector2i _size, sf::Vector2i _area);

		void fill(std::vector<ach::PhysLine*> *list);

		void sort(std::vector<ach::PhysLine*> *list);
		void sort(std::vector<ach::PhysLine*> *list, ach::Line *line);
		void sort(std::vector<ach::PhysLine*> *list, ach::Phys *phys);
	};
}

#endif
