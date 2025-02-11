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

		void fill(std::vector<ach::PhysLine*> *list, sf::FloatRect *rect);

		void sort(std::vector<ach::PhysLine*> *list);
		void sort(std::vector<ach::PhysLine*> *list, ach::Line *line);
		void sort(std::vector<ach::PhysLine*> *list, ach::Phys *phys);
	};
}

#endif
