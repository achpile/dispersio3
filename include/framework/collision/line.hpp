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
		ach::Line     line;

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

		sf::Vector2f offset();
	};


	struct PhysLineSort
	{
		bool operator()(ach::PhysLine *a, ach::PhysLine *b);
	};
}

#endif
