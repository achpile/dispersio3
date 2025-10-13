#include "meta/headers.hpp"


/***********************************************************************
     * DataMap
     * constructor

***********************************************************************/
ach::DataMap::DataMap(json_t *obj)
{
	preview = new ach::Sprite(json_object_get_string(obj, "Preview"), false, false);

	spawn   = vector_json_tile(json_object_get(obj, "Spawn"));
	player  = db->getCharacter(json_object_get_string(obj, "Player"));
	intro   = db->getCutscene(json_object_get_branch_string(obj, "Cutscene.Intro"));
	outro   = db->getCutscene(json_object_get_branch_string(obj, "Cutscene.Outro"));
	track   = db->getTrack   (json_object_get_string       (obj, "Track"));

	finish  = json_object_get_boolean(obj, "Final");
	replay  = json_object_get_boolean(obj, "Replay");
	restart = json_object_get_boolean(obj, "RestartOnDeath");

	strncpy(filename, json_object_get_string(obj, "Filename"), STR_LEN_PATH);
	strncpy(next    , json_object_get_string(obj, "Next"    ), STR_LEN_NAME);
}



/***********************************************************************
     * DataMap
     * destructor

***********************************************************************/
ach::DataMap::~DataMap()
{
	delete preview;
}



/***********************************************************************
     * DataMap
     * finalize

***********************************************************************/
void ach::DataMap::finalize()
{
	cash  = 0;
	items = 0;

	json_error_t error;
	json_t *mapdata = json_load_file(filename, 0, &error);


	if (!mapdata)
	{
		logger->log(ach::LogLevel::llError, "Error loading map: \"%s\" (%s)", filename, error.text);
		return;
	}


	size_t i, j;

	json_t *layer;
	json_t *object;

	json_array_foreach(json_object_get(mapdata, "layers"), i, layer)
	{
		if (strcmp(json_object_get_string(layer, "name"), "objects") != 0)
			continue;

		json_array_foreach(json_object_get(layer, "objects"), j, object)
		{
			if (!strcmp(json_object_get_string(object, "type"), "obj_item"))
				items++;

			if (!strcmp(json_object_get_string(object, "type"), "obj_points"))
			{
				items++;
				cash++;
			}
		}
	}
}
