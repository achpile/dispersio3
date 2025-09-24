#include "meta/headers.hpp"


/***********************************************************************
     * MapArea
     * constructor

***********************************************************************/
ach::MapArea::MapArea(json_t *obj)
{
	track = NULL;
	rect  = vector_json_rect(obj);

	if (strlen(json_property_get_string(obj, "Track")))
		track = db->getTrack(json_property_get_string(obj, "Track"));
}



/***********************************************************************
     * MapArea
     * constructor

***********************************************************************/
ach::MapArea::MapArea(sf::FloatRect _rect)
{
	track = NULL;
	rect  = _rect;
}



/***********************************************************************
     * MapArea
     * destructor

***********************************************************************/
ach::MapArea::~MapArea()
{
}
