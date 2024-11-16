#ifndef __FRAMEWORK_MATH_LINE
#define __FRAMEWORK_MATH_LINE


namespace ach
{
	struct Line
	{
		sf::Vector2f  a;
		sf::Vector2f  b;

		sf::FloatRect r;
		sf::Vector2f  v;
		sf::Vector2f  n;
		float         l;


		 Line();
		~Line();

		void set(sf::Vector2f _a, sf::Vector2f _b);
		void calc();
	};
}

#endif
