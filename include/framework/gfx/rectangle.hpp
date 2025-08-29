#ifndef __FRAMEWORK_GFX_RECTANGLE
#define __FRAMEWORK_GFX_RECTANGLE


namespace ach
{
	struct RectangleShape : sf::RectangleShape
	{
		sf::Vector2f size;

		float radius;
		int   count;


		 RectangleShape(sf::Vector2f _size = sf::Vector2f(0.0f, 0.0f));
		~RectangleShape();

		void setSize (sf::Vector2f _size);
		void setRound(bool round);

		void init(int _count, float _radius);

		std::size_t  getPointCount()             const;
		sf::Vector2f getPoint(std::size_t index) const;
	};
}

#endif
