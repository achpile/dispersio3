#include "meta/headers.hpp"


/***********************************************************************
     * EffectFall
     * constructor

***********************************************************************/
ach::EffectFall::EffectFall(sf::Vector2f pos, float _limit)
{
	limit = _limit;

	phys.init(sf::Vector2f(1.0f, 1.0f));

	phys.pos = pos;
	phys.acc = sf::Vector2f(0.0f, 1000.0f);
}



/***********************************************************************
     * EffectFall
     * destructor

***********************************************************************/
ach::EffectFall::~EffectFall()
{
}



/***********************************************************************
     * EffectFall
     * update

***********************************************************************/
bool ach::EffectFall::update()
{
	phys.update();

	if (phys.pos.y > limit)
	{
		return false;
	}

	return true;
}



/***********************************************************************
     * EffectFall
     * render

***********************************************************************/
void ach::EffectFall::render()
{
}
