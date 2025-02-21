#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectFragile
     * constructor

***********************************************************************/
ach::MapObjectFragile::MapObjectFragile(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid = true;

	cracking.set(GAME_FRAGILE_BREAKING);

	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectFragile
     * destructor

***********************************************************************/
ach::MapObjectFragile::~MapObjectFragile()
{
}



/***********************************************************************
     * MapObjectFragile
     * reset

***********************************************************************/
void ach::MapObjectFragile::reset()
{
	alive   = true;
	cracked = false;

	cracking.reset();
}



/***********************************************************************
     * MapObjectFragile
     * handle

***********************************************************************/
void ach::MapObjectFragile::handle()
{
	if (!cracked)
		return;

	if (!cracking.update())
		alive = false;
}



/***********************************************************************
     * MapObjectFragile
     * stand

***********************************************************************/
void ach::MapObjectFragile::stand(ach::Phys*)
{
	if (cracked)
		return;

	cracked = true;
}
