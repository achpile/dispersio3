#ifndef __FRAMEWORK_DATAMODEL_TYPE
#define __FRAMEWORK_DATAMODEL_TYPE


bool json_type_check         (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_object  (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_string  (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_integer (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_real    (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_boolean (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_filename(json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_array   (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_multi   (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_color   (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_link    (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_type_check_enum    (json_t *obj, json_t *dm, const char *name, const char *path);

#endif
