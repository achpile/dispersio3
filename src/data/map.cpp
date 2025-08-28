#include "meta/headers.hpp"


/***********************************************************************
     * DataMap
     * constructor

***********************************************************************/
ach::DataMap::DataMap(json_t *obj)
{
	spawn  = vector_json_tile(json_object_get(obj, "Spawn"));
	player = db->getCharacter(json_object_get_branch_string(obj, "Player"));

	finish = json_object_get_boolean(obj, "Final");
	replay = json_object_get_boolean(obj, "Replay");

	strncpy(filename, json_object_get_string(obj, "Filename"), STR_LEN_PATH);
	strncpy(track   , json_object_get_string(obj, "Track"   ), STR_LEN_PATH);
	strncpy(next    , json_object_get_string(obj, "Next"    ), STR_LEN_NAME);
}



/***********************************************************************
     * DataMap
     * destructor

***********************************************************************/
ach::DataMap::~DataMap()
{
}
