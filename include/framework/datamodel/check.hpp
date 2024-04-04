#ifndef __FRAMEWORK_DATAMODEL_CHECK
#define __FRAMEWORK_DATAMODEL_CHECK


void json_dm_check_datatypes(json_t *obj, json_t *dm, const char *path);
void json_dm_check_links(json_t *data, json_t *obj, json_t *dm);

#endif
