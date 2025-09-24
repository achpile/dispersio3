#include "meta/headers.hpp"


/***********************************************************************
     * MapArea
     * constructor

***********************************************************************/
ach::MapArea::MapArea(json_t *obj)
{
	track  = NULL;
	played = true;
	rect   = vector_json_rect(obj);

	if (strlen(json_property_get_string(obj, "Track")))
	{
		track  = db->getTrack(json_property_get_string(obj, "Track"));
		played = false;
	}
}



/***********************************************************************
     * MapArea
     * constructor

***********************************************************************/
ach::MapArea::MapArea(sf::FloatRect _rect)
{
	track  = NULL;
	played = true;
	rect   = _rect;
}



/***********************************************************************
     * MapArea
     * destructor

***********************************************************************/
ach::MapArea::~MapArea()
{
}



/***********************************************************************
     * MapArea
     * play

***********************************************************************/
bool ach::MapArea::play()
{
	if (played || !track)
		return false;

	played = true;

	track->play(false);

	return true;
}
