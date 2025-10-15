#include "meta/headers.hpp"


/***********************************************************************
     * EffectFall
     * constructor

***********************************************************************/
ach::EffectFall::EffectFall(ach::Boss *_boss, ach::DataSheet *sheet, sf::Vector2f pos, float _limit)
{
	boss  = _boss;
	limit = _limit;
	model = new ach::Model(sheet);

	phys.init(sf::Vector2f(1.0f, 1.0f));

	phys.pos = pos;
	phys.acc = sf::Vector2f(0.0f, 500.0f);
}



/***********************************************************************
     * EffectFall
     * destructor

***********************************************************************/
ach::EffectFall::~EffectFall()
{
	delete model;
}



/***********************************************************************
     * EffectFall
     * update

***********************************************************************/
bool ach::EffectFall::update()
{
	phys.update();
	model->update();

	if (phys.pos.y > limit)
	{
		boss->hit();

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
	model->render(phys.pos);
}
