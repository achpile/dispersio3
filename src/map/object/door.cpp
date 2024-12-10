#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectDoor
     * constructor

***********************************************************************/
ach::MapObjectDoor::MapObjectDoor(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	model = new ach::Model(db->getSheet(json_object_get_string(obj, "name")));
	pair  = json_property_get_integer(obj, "pair");

	if (!pair)
		logger->log(ach::LogLevel::llError, "Orphaned door ID#%d", id);
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
	gateway = map->findMapObject(pair)->phys.rect;
}



/***********************************************************************
     * MapObjectDoor
     * use

***********************************************************************/
void ach::MapObjectDoor::use()
{
	world->gateway(gateway);
}
