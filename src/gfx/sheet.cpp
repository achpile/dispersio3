#include "meta/headers.hpp"


/***********************************************************************
     * EffectSheet
     * constructor

***********************************************************************/
ach::EffectSheet::EffectSheet(ach::DataSheet *sheet, sf::Vector2f _pos, float size)
{
	pos   = _pos;
	model = new ach::Model(sheet);

	model->anim.loop = false;

	model->setScale(sheet->sheet->size.y / size);
}



/***********************************************************************
     * EffectSheet
     * destructor

***********************************************************************/
ach::EffectSheet::~EffectSheet()
{
	delete model;
}



/***********************************************************************
     * EffectSheet
     * update

***********************************************************************/
bool ach::EffectSheet::update()
{
	model->update();

	return model->anim.check();
}



/***********************************************************************
     * EffectSheet
     * render

***********************************************************************/
void ach::EffectSheet::render()
{
	model->render(pos);
}
