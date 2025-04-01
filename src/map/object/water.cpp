#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectWater
     * constructor

***********************************************************************/
ach::MapObjectWater::MapObjectWater(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
}



/***********************************************************************
     * MapObjectWater
     * destructor

***********************************************************************/
ach::MapObjectWater::~MapObjectWater()
{
}



/***********************************************************************
     * MapObjectWater
     * touch

***********************************************************************/
void ach::MapObjectWater::touch()
{
	world->player->phys.water = true;
}
