#ifndef __COLLISION_PHYS
#define __COLLISION_PHYS


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
		void init(sf::FloatRect _rect);
		void resize(sf::Vector2f _size);
		void reset();
	};
}

#endif
