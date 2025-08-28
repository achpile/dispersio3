#include "meta/headers.hpp"


/***********************************************************************
     * EffectBubble
     * constructor

***********************************************************************/
ach::EffectBubble::EffectBubble(sf::Vector2f _pos, float _limit)
{
	pos   = _pos;
	life  = 0.0f;
	limit = _limit;

	spr = new sf::CircleShape(1.0f);
	spr->setOrigin(0.5f, 0.5f);
	spr->setOutlineThickness(1.0f);
	spr->setFillColor(sf::Color::Transparent);
	spr->setOutlineColor(sf::Color::White);
}



/***********************************************************************
     * EffectBubble
     * destructor

***********************************************************************/
ach::EffectBubble::~EffectBubble()
{
	delete spr;
}



/***********************************************************************
     * EffectBubble
     * update

***********************************************************************/
bool ach::EffectBubble::update()
{
	life  += tm->get();
	pos.y -= 50.0f * tm->get();

	return pos.y > limit;
}



/***********************************************************************
     * EffectBubble
     * render

***********************************************************************/
void ach::EffectBubble::render()
{
	spr->setPosition(pos + sf::Vector2f(1.5f * sin(life * 21.37f), 0.0f));

	rm->draw(spr, ach::RenderLayer::rlGame);
}
