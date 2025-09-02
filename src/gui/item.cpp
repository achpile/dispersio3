#include "meta/headers.hpp"


/***********************************************************************
     * ItemIcon
     * constructor

***********************************************************************/
ach::ItemIcon::ItemIcon(ach::DataItem *_base, sf::Vector2f _pos)
{
	pos   = _pos;
	base  = _base;
	model = new ach::Model(base->sheet);

	model->layer = ach::RenderLayer::rlGUI;
}



/***********************************************************************
     * ItemIcon
     * destructor

***********************************************************************/
ach::ItemIcon::~ItemIcon()
{
	delete model;
}



/***********************************************************************
     * ItemIcon
     * update

***********************************************************************/
bool ach::ItemIcon::update()
{
	if (cache->getFlag(base->flag)) model->shader = ach::RenderShader::rsNone;
	else                            model->shader = ach::RenderShader::rsGrey;

	return true;
}



/***********************************************************************
     * ItemIcon
     * render

***********************************************************************/
void ach::ItemIcon::render()
{
	model->update();
	model->render(pos);
}
