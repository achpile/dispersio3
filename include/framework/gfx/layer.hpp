#ifndef __FRAMEWORK_GFX_LAYER
#define __FRAMEWORK_GFX_LAYER


namespace ach
{
	struct Layer
	{
		sf::RenderTexture *tex;
		sf::Sprite        *spr;
		sf::Vector2i       size;

		bool initialized;


		 Layer();
		~Layer();

		void init(int width, int height);
		void resize(sf::RenderWindow *window);
		void setView(sf::View view);
		void render(sf::RenderTarget *target);

		void draw(sf::Drawable *drawable, sf::RenderStates states);
		void clear(sf::Color color);
		void display();

		sf::Vector2f transform(sf::Vector2f v);
	};
}

#endif
