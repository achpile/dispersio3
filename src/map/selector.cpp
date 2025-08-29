#include "meta/headers.hpp"


/***********************************************************************
     * Selector
     * constructor

***********************************************************************/
ach::Selector::Selector()
{
	corner = new ach::Sprite(json_object_get_branch_string(dm->data, "Meta.GFX.Selector"), false, true);
	object = NULL;
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
	corner->spr->setPosition(pos);
	corner->spr->setScale(scale);

	rm->draw(corner->spr, ach::RenderLayer::rlFront);
}
