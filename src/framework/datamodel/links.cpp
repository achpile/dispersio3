#include "meta/headers.hpp"


/***********************************************************************
     * json_dm_check_links_container

***********************************************************************/
void json_dm_check_links_container(json_t *data, json_t *obj, json_t *dm)
{
	switch (json_attr_get_container(dm))
	{
		case ach::ContainerType::ctSimple : json_dm_check_links_item           (data, obj, dm); break;
		case ach::ContainerType::ctArray  : json_dm_check_links_container_array(data, obj, dm); break;
		case ach::ContainerType::ctMulti  : json_dm_check_links_container_multi(data, obj, dm); break;
		case ach::ContainerType::ctUnknown: break;
	}
}



/***********************************************************************
     * json_dm_check_links_container_array

***********************************************************************/
void json_dm_check_links_container_array(json_t *data, json_t *obj, json_t *dm)
{
	json_t     *instance;
	size_t      index;

	json_array_foreach(obj, index, instance)
		json_dm_check_links_item(data, instance, dm);
}



/***********************************************************************
     * json_dm_check_links_container_multi

***********************************************************************/
void json_dm_check_links_container_multi(json_t *data, json_t *obj, json_t *dm)
{
	json_t     *instance;
	const char *name;

	json_object_foreach(obj, name, instance)
		json_dm_check_links_item(data, instance, dm);
}



/***********************************************************************
     * json_dm_check_links_item

***********************************************************************/
void json_dm_check_links_item(json_t *data, json_t *obj, json_t *dm)
{
	switch (json_attr_get_type(dm))
	{
		case ach::DataType::dtObject  : json_dm_check_links          (data, obj, dm); break;
		case ach::DataType::dtLink    : json_dm_check_links_item_link(data, obj, dm); break;
		case ach::DataType::dtString  :
		case ach::DataType::dtInteger :
		case ach::DataType::dtReal    :
		case ach::DataType::dtBoolean :
		case ach::DataType::dtFilename:
		case ach::DataType::dtColor   :
		case ach::DataType::dtEnum    :
		case ach::DataType::dtUnknown : break;
	}
}



/***********************************************************************
     * json_dm_check_links_item_link

***********************************************************************/
void json_dm_check_links_item_link(json_t *data, json_t *obj, json_t *dm)
{
	char path[STR_LEN_PATH];

	snprintf(path, STR_LEN_PATH, "%s.%s", json_attr_get_data(dm), json_string_value(obj));

	if (!json_object_get_branch(data, path))
	{
		logger->log(ach::LogLevel::llWarning, "Linked object '%s' is not found", path);
		json_string_set(obj, json_string_value(json_attr_get_default(dm)));
	}
}
