#include "meta/headers.hpp"


/***********************************************************************
     * Selector
     * constructor

***********************************************************************/
ach::Selector::Selector()
{
	life   = 0.0f;
	object = NULL;
	corner = new ach::Sprite(json_object_get_branch_string(dm->data, "Meta.GFX.Selector"), false, true);
}



/***********************************************************************
     * Selector
     * destructor

***********************************************************************/
ach::Selector::~Selector()
{
	delete corner;
}



/***********************************************************************
     * Selector
     * update

***********************************************************************/
void ach::Selector::update()
{
	object  = NULL;
	life   += tm->get();
}



/***********************************************************************
     * Selector
     * render

***********************************************************************/
void ach::Selector::render()
{
	if (!object)
		return;

	draw(rect_lt(object->phys.rect), sf::Vector2f( 1,  1));
	draw(rect_rt(object->phys.rect), sf::Vector2f(-1,  1));
	draw(rect_lb(object->phys.rect), sf::Vector2f( 1, -1));
	draw(rect_rb(object->phys.rect), sf::Vector2f(-1, -1));
}



/***********************************************************************
     * Selector
     * draw

***********************************************************************/
void ach::Selector::draw(sf::Vector2f pos, sf::Vector2f scale)
{
	float offset = sin(life * 10.0f);

	corner->spr->setPosition(pos + scale * offset);
	corner->spr->setScale(scale);

	rm->draw(corner->spr, ach::RenderLayer::rlFront);
}
