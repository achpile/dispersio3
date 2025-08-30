#ifndef __GUI_SELECTOR
#define __GUI_SELECTOR


namespace ach
{
	struct Selector
	{
		ach::Phys   *object;
		ach::Sprite *corner;

		float life;


		 Selector();
		~Selector();

		void update();
		void render();

		void draw(sf::Vector2f pos, sf::Vector2f scale);
	};
}

#endif
