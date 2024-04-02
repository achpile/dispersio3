#ifndef __FRAMEWORK_JSON_BRANCH
#define __FRAMEWORK_JSON_BRANCH


json_t *json_object_get_branch(json_t *root, const char *path);
void    json_object_set_branch(json_t *root, const char *path, json_t *obj);

#endif
