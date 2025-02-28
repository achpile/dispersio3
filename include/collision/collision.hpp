#ifndef __COLLISION_COLLISION
#define __COLLISION_COLLISION


namespace ach
{
	struct Collision
	{
		std::vector<ach::PhysLine*> lines;

		ach::Quadrant ***quad;
		sf::Vector2i     size;


		 Collision();
		~Collision();

		void split(sf::Vector2i _size);

		void fill(std::vector<ach::PhysLine*> *list, long filter, sf::FloatRect *rect);

		void sort(std::vector<ach::PhysLine*> *list);
		void sort(std::vector<ach::PhysLine*> *list, long filter, ach::Line *line);
		void sort(std::vector<ach::PhysLine*> *list, long filter, ach::Phys *phys);
	};
}

#endif
