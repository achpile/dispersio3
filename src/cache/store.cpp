#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * spawn

***********************************************************************/
int ach::Cache::spawn()
{
	return json_object_get_branch_integer(cache, "Current.Checkpoint");
}



/***********************************************************************
     * Cache
     * die

***********************************************************************/
void ach::Cache::die()
{
	deaths++;

	store();
}



/***********************************************************************
     * Cache
     * collect

***********************************************************************/
void ach::Cache::collect(int id)
{
	json_array_append_new(json_object_get(info, "Item"), json_integer(id));

	store();
}



/***********************************************************************
     * Cache
     * checkpoint

***********************************************************************/
void ach::Cache::checkpoint(int id)
{
	json_object_set_branch_integer(cache, "Current.Checkpoint", id);

	store();
}
