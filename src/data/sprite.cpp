#include "meta/headers.hpp"


/***********************************************************************
     * DataSprite
     * constructor

***********************************************************************/
ach::DataSprite::DataSprite(json_t *obj)
{
	spr = new ach::Sprite(json_object_get_string (obj, "Filename"), false, true);
}



/***********************************************************************
     * DataSprite
     * destructor

***********************************************************************/
ach::DataSprite::~DataSprite()
{
	delete spr;
}
