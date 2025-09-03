#include "meta/headers.hpp"


/***********************************************************************
     * DataCutscene
     * constructor

***********************************************************************/
ach::DataCutscene::DataCutscene(json_t *obj)
{
	json_t *slide;
	size_t  index;

	json_array_foreach(json_object_get(obj, "Slideshow"), index, slide)
		slideshow.push_back(new ach::Sprite(json_string_value(slide), false, true));

	strncpy(track, json_object_get_string(obj, "Track"), STR_LEN_PATH);
	strncpy(text , json_object_get_string(obj, "Text" ), STR_LEN_NAME);
}



/***********************************************************************
     * DataCutscene
     * destructor

***********************************************************************/
ach::DataCutscene::~DataCutscene()
{
	list_delete(slideshow);
}
