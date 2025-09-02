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


	enum RenderShader
	{
		rsNone,
		rsWhite,
		rsGrey
	};


	struct RenderManager
	{
		ach::Layer *bg;
		ach::Layer *game;
		ach::Layer *effect;
		ach::Layer *front;
		ach::Layer *gui;

		ach::Shader *none;
		ach::Shader *white;
		ach::Shader *grey;


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

		void draw(sf::Drawable *drawable, ach::RenderLayer layer = ach::RenderLayer::rlGUI, ach::RenderShader shader = ach::RenderShader::rsNone);

		void          initLayer(ach::RenderLayer layer, int width, int height, bool smooth);
		ach::Layer   *getLayer (ach::RenderLayer layer);
		ach::Shader  *getShader(ach::RenderShader shader);
		sf::Vector2f  transform(ach::RenderLayer layer, sf::Vector2f v);
	};
}

#endif
