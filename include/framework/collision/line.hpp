#ifndef __FRAMEWORK_COLLISION_LINE
#define __FRAMEWORK_COLLISION_LINE


namespace ach
{
	enum PhysType
	{
		ptSolid = 0,
		ptPlatform
	};


	struct PhysLine
	{
		ach::PhysType type;

		sf::Vector2f  a;
		sf::Vector2f  b;
		sf::Vector2f  l;

		float len;


		 PhysLine(ach::PhysType _type, sf::Vector2f _a, sf::Vector2f _b, sf::Vector2f pos);
		~PhysLine();
	};
}

#endif
