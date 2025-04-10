#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectYoku
     * constructor

***********************************************************************/
ach::MapObjectYoku::MapObjectYoku(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid  = true;
	sfx    = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Yoku"));

	setSheet(json_object_get_string(obj, "name"));

	model->anim.loop = false;
	model->layer     = ach::RenderLayer::rlFront;
}



/***********************************************************************
     * MapObjectYoku
     * destructor

***********************************************************************/
ach::MapObjectYoku::~MapObjectYoku()
{
}



/***********************************************************************
     * MapObjectYoku
     * reset

***********************************************************************/
void ach::MapObjectYoku::reset()
{
}



/***********************************************************************
     * MapObjectYoku
     * handle

***********************************************************************/
void ach::MapObjectYoku::handle()
{
}
