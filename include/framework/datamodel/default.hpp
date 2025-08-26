#ifndef __FRAMEWORK_DATAMODEL_DEFAULT
#define __FRAMEWORK_DATAMODEL_DEFAULT


json_t *json_dm_generate_default           (json_t *obj, json_t *dm);
void    json_dm_generate_default_item      (json_t *obj, json_t *dm, const char *key);
void    json_dm_generate_default_item_array(json_t *obj, json_t *dm);
void    json_dm_generate_default_array     (json_t *obj, json_t *dm, const char *key);
void    json_dm_generate_default_multi     (json_t *obj, json_t *dm, const char *key);
void    json_dm_generate_default_object    (json_t *obj, json_t *dm, const char *key);
void    json_dm_generate_default_value     (json_t *obj, json_t *dm, const char *key);

#endif
