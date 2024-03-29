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
void ach::RenderManager::display()
{
	gui->display();

	gui->render(app->window);
}
