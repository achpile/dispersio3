#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * goal

***********************************************************************/
void ach::Cache::goal()
{
	json_object_set_boolean(info, "Finished", true);

	select(current->next, ach::LevelMode::lmNavigation);

	save();
}



/***********************************************************************
     * Cache
     * die

***********************************************************************/
void ach::Cache::die()
{
	deaths++;

	save();
}



/***********************************************************************
     * Cache
     * collect

***********************************************************************/
void ach::Cache::collect(int id)
{
	json_array_append_new(json_object_get(info, "Item"), json_integer(id));

	save();
}



/***********************************************************************
     * Cache
     * checkpoint

***********************************************************************/
void ach::Cache::checkpoint(int id)
{
	json_object_set_branch_integer(cache, "Current.Checkpoint", id);

	save();
}
