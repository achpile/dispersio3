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
		float d;
		float k;
		float o;
		bool  v;


		 PhysLine(ach::PhysType _type, sf::Vector2f _a, sf::Vector2f _b, sf::Vector2f pos);
		~PhysLine();

		void  calc();
		bool  check(ach::Phys *phys);
		float diff(float x, float left, float right, bool max);
		float value(float x);

		bool collideBox(sf::FloatRect box, sf::Vector2f *c = NULL, sf::Vector2f *n = NULL);

		sf::Vector2f offset();
	};
}

#endif
