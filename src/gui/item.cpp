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
	if (cache->getFlag(base->flag)) model->state = rm->states.none;
	else                            model->state = rm->states.grey;

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
