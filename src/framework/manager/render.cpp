#include "meta/headers.hpp"


/***********************************************************************
     * RenderManager
     * constructor

***********************************************************************/
ach::RenderManager::RenderManager()
{
	bg     = new ach::Layer();
	game   = new ach::Layer();
	effect = new ach::Layer();
	front  = new ach::Layer();
	gui    = new ach::Layer();
}



/***********************************************************************
     * RenderManager
     * destructor

***********************************************************************/
ach::RenderManager::~RenderManager()
{
	delete bg;
	delete game;
	delete effect;
	delete front;
	delete gui;
}



/***********************************************************************
     * RenderManager
     * clear

***********************************************************************/
void ach::RenderManager::clear()
{
	bg->clear(sf::Color::Black);
	game->clear(sf::Color::Transparent);
	effect->clear(sf::Color::Transparent);
	front->clear(sf::Color::Transparent);
	gui->clear(sf::Color::Transparent);
}



/***********************************************************************
     * RenderManager
     * reset

***********************************************************************/
void ach::RenderManager::reset()
{
	setColor(sf::Color::White);
}



/***********************************************************************
     * RenderManager
     * display

***********************************************************************/
void ach::RenderManager::display(sf::RenderWindow *window)
{
	bg->display();
	game->display();
	effect->display();
	front->display();
	gui->display();

	bg->render(window);
	game->render(window);
	effect->render(window);
	front->render(window);
	gui->render(window);
}



/***********************************************************************
     * RenderManager
     * resize

***********************************************************************/
void ach::RenderManager::resize(sf::RenderWindow *window)
{
	window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));

	bg->resize(window);
	game->resize(window);
	effect->resize(window);
	front->resize(window);
	gui->resize(window);
}



/***********************************************************************
     * RenderManager
     * setView

***********************************************************************/
void ach::RenderManager::setView(sf::View view)
{
	game->setView(view);
	effect->setView(view);
	front->setView(view);
}



/***********************************************************************
     * RenderManager
     * setSmooth

***********************************************************************/
void ach::RenderManager::setSmooth(bool smooth)
{
	bg->setSmooth(smooth);
	game->setSmooth(smooth);
	effect->setSmooth(smooth);
	front->setSmooth(smooth);
	gui->setSmooth(smooth);
}



/***********************************************************************
     * RenderManager
     * setColor

***********************************************************************/
void ach::RenderManager::setColor(sf::Color color)
{
	bg->setColor(color);
	game->setColor(color);
	effect->setColor(color);
	front->setColor(color);
	gui->setColor(color);
}



/***********************************************************************
     * RenderManager
     * setFade

***********************************************************************/
void ach::RenderManager::setFade(float value)
{
	int c = 255 * interval_set(value, 0.0f, 1.0f);

	setColor(sf::Color(c, c, c, 255));
}



/***********************************************************************
     * RenderManager
     * draw

***********************************************************************/
void ach::RenderManager::draw(sf::Drawable *drawable, ach::RenderLayer layer, sf::RenderStates states)
{
	getLayer(layer)->draw(drawable, states);
}



/***********************************************************************
     * RenderManager
     * initLayer

***********************************************************************/
void ach::RenderManager::initLayer(ach::RenderLayer layer, int width, int height, bool smooth)
{
	getLayer(layer)->init(width, height, smooth);
}



/***********************************************************************
     * RenderManager
     * getLayer

***********************************************************************/
ach::Layer* ach::RenderManager::getLayer(ach::RenderLayer layer)
{
	switch (layer)
	{
		case ach::RenderLayer::rlBG    : return bg;
		case ach::RenderLayer::rlGame  : return game;
		case ach::RenderLayer::rlEffect: return effect;
		case ach::RenderLayer::rlFront : return front;
		case ach::RenderLayer::rlGUI   : return gui;
	}

	return NULL;
}



/***********************************************************************
     * RenderManager
     * transform

***********************************************************************/
sf::Vector2f ach::RenderManager::transform(ach::RenderLayer layer, sf::Vector2f v)
{
	return getLayer(layer)->transform(v);
}
