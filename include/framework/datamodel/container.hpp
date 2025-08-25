#ifndef __FRAMEWORK_DATAMODEL_CONTAINER
#define __FRAMEWORK_DATAMODEL_CONTAINER


bool json_container_check         (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_container_check_simple  (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_container_check_array   (json_t *obj, json_t *dm, const char *name, const char *path);
bool json_container_check_multi   (json_t *obj, json_t *dm, const char *name, const char *path);

#endif
