#include "meta/headers.hpp"


/***********************************************************************
     * Layer
     * constructor

***********************************************************************/
ach::Layer::Layer(int width, int height)
{
	spr = new sf::Sprite();
	tex = new sf::RenderTexture();

	tex->create(width, height);
	tex->setRepeated(false);
	tex->setActive(true);
	tex->setSmooth(true);

	spr->setTexture(tex->getTexture());
	spr->setOrigin(sf::Vector2f(tex->getSize()) / 2.0f);
}



/***********************************************************************
     * Layer
     * destructor

***********************************************************************/
ach::Layer::~Layer()
{
	delete spr;
	delete tex;
}



/***********************************************************************
     * Layer
     * clear

***********************************************************************/
void ach::Layer::clear(sf::Color color)
{
	tex->clear(color);
}



/***********************************************************************
     * Layer
     * display

***********************************************************************/
void ach::Layer::display()
{
	tex->display();
}



/***********************************************************************
     * Layer
     * resize

***********************************************************************/
void ach::Layer::resize(sf::RenderWindow *window)
{
	float scale = std::min((float)window->getSize().x / (float)tex->getSize().x,
	                       (float)window->getSize().y / (float)tex->getSize().y);

	spr->setPosition(sf::Vector2f(window->getSize()) / 2.0f);
	spr->setScale(scale, scale);
}



/***********************************************************************
     * Layer
     * setView

***********************************************************************/
void ach::Layer::setView(sf::View view)
{
	tex->setView(view);
}



/***********************************************************************
     * Layer
     * render

***********************************************************************/
void ach::Layer::render(sf::RenderTarget *target)
{
	target->draw(*spr);
}



/***********************************************************************
     * Layer
     * draw

***********************************************************************/
void ach::Layer::draw(sf::Drawable *drawable, sf::RenderStates states)
{
	tex->draw(*drawable, states);
}
