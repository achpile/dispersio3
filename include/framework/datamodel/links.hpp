#ifndef __FRAMEWORK_DATAMODEL_LINKS
#define __FRAMEWORK_DATAMODEL_LINKS


void json_dm_check_links_item(json_t *data, json_t *obj, json_t *dm);
void json_dm_check_links_item_link(json_t *data, json_t *obj, json_t *dm);
void json_dm_check_links_container(json_t *data, json_t *obj, json_t *dm);
void json_dm_check_links_container_multi(json_t *data, json_t *obj, json_t *dm);
void json_dm_check_links_container_array(json_t *data, json_t *obj, json_t *dm);

#endif
