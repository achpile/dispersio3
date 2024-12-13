#include "meta/headers.hpp"


/***********************************************************************
     * Background
     * constructor

***********************************************************************/
ach::Background::Background(const char *filename, float _factor)
{
	factor = _factor;
	spr    = new ach::Sprite(filename, true, false);
}



/***********************************************************************
     * Background
     * destructor

***********************************************************************/
ach::Background::~Background()
{
	delete spr;
}



/***********************************************************************
     * Background
     * render

***********************************************************************/
void ach::Background::render(float offset)
{
	spr->spr->setTextureRect(sf::IntRect(offset * factor, 0, rect.x, rect.y));

	rm->draw(spr->spr, ach::RenderLayer::rlBG);
}



/***********************************************************************
     * Background
     * setSize

***********************************************************************/
void ach::Background::setSize(int width, int height)
{
	size   = sf::Vector2i(width, height);
	scale  = height / spr->size.y;
	rect.x = ceil(width / scale);
	rect.y = spr->size.y;

	spr->spr->setScale(sf::Vector2f(scale, scale));
}
