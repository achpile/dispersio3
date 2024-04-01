#include "meta/headers.hpp"


/***********************************************************************
     * RenderManager
     * constructor

***********************************************************************/
ach::RenderManager::RenderManager()
{
	gui = new ach::Layer(1280, 800);
}



/***********************************************************************
     * RenderManager
     * destructor

***********************************************************************/
ach::RenderManager::~RenderManager()
{
	delete gui;
}



/***********************************************************************
     * RenderManager
     * getLayer

***********************************************************************/
ach::Layer* ach::RenderManager::getLayer(ach::RenderLayer layer)
{
	switch (layer)
	{
		case ach::RenderLayer::rlGUI: return gui;
		default                     : return NULL;
	}
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
     * clear

***********************************************************************/
void ach::RenderManager::clear()
{
	gui->clear(sf::Color::Transparent);
}



/***********************************************************************
     * RenderManager
     * display

***********************************************************************/
void ach::RenderManager::display(sf::RenderWindow *window)
{
	gui->display();

	gui->render(window);
}



/***********************************************************************
     * RenderManager
     * resize

***********************************************************************/
void ach::RenderManager::resize(sf::RenderWindow *window)
{
	window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));

	gui->resize(window);
}
