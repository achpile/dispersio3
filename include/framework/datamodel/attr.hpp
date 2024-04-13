#ifndef __FRAMEWORK_DATAMODEL_ATTR
#define __FRAMEWORK_DATAMODEL_ATTR


namespace ach
{
	enum JSONtype
	{
		jtUnknown = 0,
		jtObject,
		jtString,
		jtInteger,
		jtReal,
		jtBoolean,
		jtFilename,
		jtColor,
		jtArray,
		jtMulti,
		jtLink
	};
}


ach::JSONtype  json_attr_get_type(json_t *obj);
json_t        *json_attr_get_default(json_t *obj);
json_t        *json_attr_get_traits(json_t *obj);
size_t         json_attr_get_maxlen(json_t *obj);
int            json_attr_get_min(json_t *obj);
int            json_attr_get_max(json_t *obj);
float          json_attr_get_min_real(json_t *obj);
float          json_attr_get_max_real(json_t *obj);
const char    *json_attr_get_data(json_t *obj);

#endif
