#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectWater
     * constructor

***********************************************************************/
ach::MapObjectWater::MapObjectWater(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	shape = new sf::RectangleShape();

	shape->setSize     (rect_size(phys.rect));
	shape->setPosition (rect_pos (phys.rect));
	shape->setFillColor(sf::Color(0, 0, 255, 127));
}



/***********************************************************************
     * MapObjectWater
     * destructor

***********************************************************************/
ach::MapObjectWater::~MapObjectWater()
{
	delete shape;
}



/***********************************************************************
     * MapObjectWater
     * touch

***********************************************************************/
void ach::MapObjectWater::touch()
{
	world->player->phys.water = phys.rect.top;
}



/***********************************************************************
     * MapObjectWater
     * post

***********************************************************************/
void ach::MapObjectWater::post()
{
	rm->draw(shape, ach::RenderLayer::rlEffect);
}
