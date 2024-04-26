#ifndef __FRAMEWORK_GFX_LAYER
#define __FRAMEWORK_GFX_LAYER


namespace ach
{
	struct Layer
	{
		sf::RenderTexture *tex;
		sf::Sprite        *spr;


		 Layer(int width, int height);
		~Layer();

		void clear(sf::Color color);
		void display();
		void resize(sf::RenderWindow *window);
		void setView(sf::View view);
		void render(sf::RenderTarget *target);
		void draw(sf::Drawable *drawable, sf::RenderStates states);
	};
}

#endif
