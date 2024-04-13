#ifndef __FRAMEWORK_DATAMODEL_TRAIT
#define __FRAMEWORK_DATAMODEL_TRAIT


void json_dm_trait_process(json_t *obj, json_t *traits);
void json_dm_trait_add_list(json_t *obj, json_t *traits, json_t *list);
void json_dm_trait_add(json_t *obj, json_t *trait);

#endif
