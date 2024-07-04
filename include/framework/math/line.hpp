#ifndef __FRAMEWORK_MATH_LINE
#define __FRAMEWORK_MATH_LINE


namespace ach
{
	struct Line
	{
		sf::Vector2f a;
		sf::Vector2f b;

		sf::Vector2f v;
		float        l;


		 Line();
		~Line();

		void set(sf::Vector2f _a, sf::Vector2f _b);
	};
}

#endif
