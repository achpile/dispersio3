#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * constructor

***********************************************************************/
ach::Cache::Cache()
{
	campaign = json_object_get_branch(dm->data, "Data.Game.Campaign");
	cache    = json_object_get_branch(dm->data, "Data.Game.Cache");
}



/***********************************************************************
     * Cache
     * destructor

***********************************************************************/
ach::Cache::~Cache()
{
	save();
}



/***********************************************************************
     * Cache
     * init

***********************************************************************/
void ach::Cache::init()
{
	current = db->getMap(json_object_get_string(campaign, "Start"));
}



/***********************************************************************
     * Cache
     * save

***********************************************************************/
void ach::Cache::save()
{
	json_dump_file(cache, FILE_CACHE, JSON_INDENT(4) | JSON_SORT_KEYS);
}



/***********************************************************************
     * Cache
     * reset

***********************************************************************/
void ach::Cache::reset()
{
	cache = json_dm_generate_default(NULL, json_object_get_branch(dm->dm, "Data.Game.Cache"));

	json_object_set_branch(dm->data, "Data.Game.Cache", cache);
}



/***********************************************************************
     * Cache
     * finish

***********************************************************************/
void ach::Cache::finish()
{
	current = db->getMap(current->next);
}
