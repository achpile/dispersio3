#include "meta/headers.hpp"


/***********************************************************************
     * Effect
     * constructor

***********************************************************************/
ach::Effect::Effect(sf::Vector2f, sf::Vector2f, sf::Color)
{
}



/***********************************************************************
     * Effect
     * destructor

***********************************************************************/
ach::Effect::~Effect()
{
}



/***********************************************************************
     * Effect
     * update

***********************************************************************/
bool ach::Effect::update()
{
	return false;
}



/***********************************************************************
     * Effect
     * create

***********************************************************************/
ach::Effect* ach::Effect::create(ach::EffectType type, sf::Vector2f pos, sf::Vector2f dir, sf::Color color)
{
	switch (type)
	{
		case ach::EffectType::etNone : return new ach::Effect     (pos, dir, color);
		case ach::EffectType::etSpark: return new ach::EffectSpark(pos, dir, color);

		default                      : return new ach::Effect     (pos, dir, color);
	}
}
