#ifndef __FRAMEWORK_JSON_PROPERTY
#define __FRAMEWORK_JSON_PROPERTY


bool    json_property    (json_t *obj, const char *name);
bool    json_class       (json_t *obj, const char *name);

json_t* json_property_get(json_t *obj, const char *name);
json_t* json_class_get   (json_t *obj, const char *name, const char *value);

#endif
