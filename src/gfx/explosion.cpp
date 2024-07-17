#include "meta/headers.hpp"


/***********************************************************************
     * EffectExplosion
     * constructor

***********************************************************************/
ach::EffectExplosion::EffectExplosion(ach::DataSheet *sheet, sf::Vector2f _pos, float radius)
{
	pos   = _pos;
	model = new ach::Model(sheet);

	model->anim.loop = false;

	model->setScale(sheet->sheet->size.y / (2 * radius));
}



/***********************************************************************
     * EffectExplosion
     * destructor

***********************************************************************/
ach::EffectExplosion::~EffectExplosion()
{
	delete model;
}



/***********************************************************************
     * EffectExplosion
     * update

***********************************************************************/
bool ach::EffectExplosion::update()
{
	model->update();

	return model->anim.check();
}



/***********************************************************************
     * EffectExplosion
     * render

***********************************************************************/
void ach::EffectExplosion::render()
{
	model->render(pos);
}
