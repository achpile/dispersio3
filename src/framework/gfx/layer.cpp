#include "meta/headers.hpp"


/***********************************************************************
     * Layer
     * constructor

***********************************************************************/
ach::Layer::Layer()
{
	spr = new sf::Sprite();
	tex = new sf::RenderTexture();

	initialized = false;
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
     * init

***********************************************************************/
void ach::Layer::init(int width, int height, bool smooth)
{
	tex->create(width, height);
	tex->setRepeated(false);
	tex->setActive(true);
	tex->setSmooth(smooth);

	spr->setTexture(tex->getTexture());
	spr->setOrigin(sf::Vector2f(width / 2.0f, height / 2.0f));

	size        = sf::Vector2i(width, height);
	initialized = true;
}



/***********************************************************************
     * Layer
     * resize

***********************************************************************/
void ach::Layer::resize(sf::RenderWindow *window)
{
	if (!initialized)
		return;

	float scale = std::min((float)window->getSize().x / size.x,
	                       (float)window->getSize().y / size.y);

	spr->setPosition(sf::Vector2f(window->getSize()) / 2.0f);
	spr->setScale(scale, scale);
}



/***********************************************************************
     * Layer
     * render

***********************************************************************/
void ach::Layer::render(sf::RenderTarget *target)
{
	if (!initialized)
		return;

	target->draw(*spr);
}



/***********************************************************************
     * Layer
     * setView

***********************************************************************/
void ach::Layer::setView(sf::View view)
{
	if (!initialized)
		return;

	tex->setView(view);
}



/***********************************************************************
     * Layer
     * setSmooth

***********************************************************************/
void ach::Layer::setSmooth(bool smooth)
{
	if (!initialized)
		return;

	tex->setSmooth(smooth);
}



/***********************************************************************
     * Layer
     * draw

***********************************************************************/
void ach::Layer::draw(sf::Drawable *drawable, sf::RenderStates states)
{
	if (!initialized)
		return;

	tex->draw(*drawable, states);
}



/***********************************************************************
     * Layer
     * clear

***********************************************************************/
void ach::Layer::clear(sf::Color color)
{
	if (!initialized)
		return;

	tex->clear(color);
}



/***********************************************************************
     * Layer
     * display

***********************************************************************/
void ach::Layer::display()
{
	if (!initialized)
		return;

	tex->display();
}



/***********************************************************************
     * Layer
     * transform

***********************************************************************/
sf::Vector2f ach::Layer::transform(sf::Vector2f v)
{
	if (!initialized)
		return v;

	return spr->getInverseTransform().transformPoint(v.x, v.y);
}
