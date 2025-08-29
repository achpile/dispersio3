#ifndef __FRAMEWORK_GFX_ROUNDED
#define __FRAMEWORK_GFX_ROUNDED


namespace ach
{
	struct RoundedRectangle : sf::RectangleShape
	{
		sf::Vector2f size;

		float radius;
		int   count;


		 RoundedRectangle(sf::Vector2f _size);
		~RoundedRectangle();

		void setSize(sf::Vector2f _size);

		std::size_t  getPointCount()             const;
		sf::Vector2f getPoint(std::size_t index) const;
	};
}

#endif
