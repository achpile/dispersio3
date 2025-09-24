#include "meta/headers.hpp"


/***********************************************************************
     * DataTrack
     * constructor

***********************************************************************/
ach::DataTrack::DataTrack(json_t *obj)
{
	loop = json_object_get_boolean(obj, "Loop");

	strncpy(filename, json_object_get_string(obj, "Filename"), STR_LEN_PATH);
}



/***********************************************************************
     * DataTrack
     * destructor

***********************************************************************/
ach::DataTrack::~DataTrack()
{
}
