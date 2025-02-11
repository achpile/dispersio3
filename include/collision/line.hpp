#ifndef __COLLISION_LINE
#define __COLLISION_LINE


namespace ach
{
	enum PhysType
	{
		ptSolid = 0,
		ptPlatform,
		ptBarrier,
		ptDeath
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

		bool  check(ach::Phys *p);
		bool  check(ach::Line *l);

		bool  collide(ach::Phys *p);
		bool  collide(ach::Line *l);

		sf::Vector2f offsetPhys();

		static bool sort(ach::PhysLine *a, ach::PhysLine *b);
		static bool remove(ach::PhysLine *l);
	};
}

#endif
