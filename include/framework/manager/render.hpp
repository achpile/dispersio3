#ifndef __FRAMEWORK_MANAGER_RENDER
#define __FRAMEWORK_MANAGER_RENDER


namespace ach
{
	enum RenderLayer
	{
		rlBG,
		rlGame,
		rlEffect,
		rlFront,
		rlGUI
	};


	struct RenderManager
	{
		ach::Layer *bg;
		ach::Layer *game;
		ach::Layer *effect;
		ach::Layer *front;
		ach::Layer *gui;


		 RenderManager();
		~RenderManager();

		void clear();
		void reset();
		void display(sf::RenderWindow *window);
		void resize (sf::RenderWindow *window);

		void setView  (sf::View view);
		void setSmooth(bool smooth);
		void setColor (sf::Color color);
		void setFade  (float value);

		void draw(sf::Drawable *drawable, ach::RenderLayer layer = ach::RenderLayer::rlGUI, sf::RenderStates states = sf::RenderStates::Default);

		void          initLayer(ach::RenderLayer layer, int width, int height, bool smooth);
		ach::Layer   *getLayer (ach::RenderLayer layer);
		sf::Vector2f  transform(ach::RenderLayer layer, sf::Vector2f v);
	};
}

#endif
