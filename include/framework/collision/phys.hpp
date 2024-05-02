#ifndef __FRAMEWORK_COLLISION_PHYS
#define __FRAMEWORK_COLLISION_PHYS


namespace ach
{
	struct Phys
	{
		sf::Vector2f  pos;
		sf::Vector2f  vel;
		sf::Vector2f  acc;

		sf::Vector2f  size;
		sf::FloatRect rect;

		bool grounded;
		bool moving;
		bool jumpdown;


		void update();
		void calc();
		void init(sf::Vector2f _size);
	};
}

#endif
