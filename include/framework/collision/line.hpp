#ifndef __FRAMEWORK_COLLISION_LINE
#define __FRAMEWORK_COLLISION_LINE


namespace ach
{
	struct PhysLine
	{
		sf::Vector2f a;
		sf::Vector2f b;
		sf::Vector2f l;

		float len;
		bool  solid;


		 PhysLine(sf::Vector2f _a, sf::Vector2f _l, sf::Vector2f pos, bool _solid);
		~PhysLine();
	};
}

#endif
