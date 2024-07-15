#ifndef __FRAMEWORK_COLLISION_LINE
#define __FRAMEWORK_COLLISION_LINE


namespace ach
{
	enum PhysType
	{
		ptSolid = 0,
		ptPlatform,
		ptBarrier
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
		float diff(float x, float left, float right, bool max);
		float value(float x);

		bool  dist(ach::Phys *phys);

		bool  collide(ach::Phys *phys);

		sf::Vector2f offsetPhys();

		static bool sort(ach::PhysLine *a, ach::PhysLine *b);
	};
}

#endif
