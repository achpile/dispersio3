#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectDoor
     * constructor

***********************************************************************/
ach::MapObjectDoor::MapObjectDoor(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	pair = json_property_get_integer(obj, "Pair");

	if (!pair)
		logger->log(ach::LogLevel::llError, "Orphaned door ID#%d", id);

	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectDoor
     * destructor

***********************************************************************/
ach::MapObjectDoor::~MapObjectDoor()
{
}



/***********************************************************************
     * MapObjectDoor
     * init

***********************************************************************/
void ach::MapObjectDoor::init(ach::Map *map)
{
	if (pair)
		gateway = map->findMapObject(pair)->phys.rect;
}



/***********************************************************************
     * MapObjectDoor
     * use

***********************************************************************/
void ach::MapObjectDoor::use()
{
	if (pair)
		world->gateway(gateway);
}
