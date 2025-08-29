#ifndef __MAP_SELECTOR
#define __MAP_SELECTOR


namespace ach
{
	struct Selector
	{
		ach::MapObject *object;
		ach::Sprite    *corner;


		 Selector();
		~Selector();

		void update();
		void render();

		void draw(sf::Vector2f pos, sf::Vector2f scale);
	};
}

#endif
