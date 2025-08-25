#include "meta/headers.hpp"


/***********************************************************************
     * json_container_check

***********************************************************************/
bool json_container_check(json_t *obj, json_t *dm, const char *name, const char *path)
{
	switch (json_attr_get_container(dm))
	{
		case ach::ContainerType::ctSimple : return json_container_check_simple(obj, dm, name, path);
		case ach::ContainerType::ctArray  : return json_container_check_array (obj, dm, name, path);
		case ach::ContainerType::ctMulti  : return json_container_check_multi (obj, dm, name, path);
		case ach::ContainerType::ctUnknown: return false;
	}

	return false;
}



/***********************************************************************
     * json_container_check_simple

***********************************************************************/
bool json_container_check_simple(json_t *obj, json_t *dm, const char *name, const char *path)
{
	return json_type_check(obj, dm, name, path);
}



/***********************************************************************
     * json_container_check_array

***********************************************************************/
bool json_container_check_array(json_t *obj, json_t *dm, const char *name, const char *path)
{
	return json_type_check(obj, dm, name, path);
}



/***********************************************************************
     * json_container_check_multi

***********************************************************************/
bool json_container_check_multi(json_t *obj, json_t *dm, const char *name, const char *path)
{
	return json_type_check(obj, dm, name, path);
}
