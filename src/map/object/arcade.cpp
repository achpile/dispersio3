#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectArcade
     * constructor

***********************************************************************/
ach::MapObjectArcade::MapObjectArcade(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectArcade
     * destructor

***********************************************************************/
ach::MapObjectArcade::~MapObjectArcade()
{
}



/***********************************************************************
     * MapObjectArcade
     * touch

***********************************************************************/
void ach::MapObjectArcade::touch()
{
	select();
}



/***********************************************************************
     * MapObjectArcade
     * use

***********************************************************************/
void ach::MapObjectArcade::use()
{
	world->play();
	sm->play(theme->menu.pick);
}
