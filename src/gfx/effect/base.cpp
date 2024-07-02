#include "meta/headers.hpp"


/***********************************************************************
     * Effect
     * constructor

***********************************************************************/
ach::Effect::Effect(sf::Vector2f)
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
ach::Effect* ach::Effect::create(ach::EffectType type, sf::Vector2f pos)
{
	switch (type)
	{
		case ach::EffectType::etNone: return new ach::Effect(pos);

		default                     : return new ach::Effect(pos);
	}
}
