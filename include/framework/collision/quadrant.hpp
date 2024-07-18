#ifndef __FRAMEWORK_COLLISION_QUADRANT
#define __FRAMEWORK_COLLISION_QUADRANT


namespace ach
{
	struct Quadrant
	{
		sf::FloatRect               rect;
		std::vector<ach::PhysLine*> lines;


		 Quadrant(sf::Vector2i pos, sf::Vector2i size);
		~Quadrant();
	};
}

#endif
