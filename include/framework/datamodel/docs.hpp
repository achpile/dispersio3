#ifndef __FRAMEWORK_DATAMODEL_DOCS
#define __FRAMEWORK_DATAMODEL_DOCS


void dm_docs_generate(json_t *obj, const char *filename);

void dm_docs_generate_header   (FILE *fp);
void dm_docs_generate_contents (FILE *fp, json_t *obj);
void dm_docs_generate_table    (FILE *fp, json_t *obj);
void dm_docs_generate_footer   (FILE *fp);
void dm_docs_generate_recursive(FILE *fp, json_t *obj, bool listing, const char *path, const char *name, bool skip);
void dm_docs_generate_foreach  (FILE *fp, json_t *obj, bool listing, const char *current, bool container);
void dm_docs_generate_item_link(FILE *fp, const char *path);
void dm_docs_generate_item_row (FILE *fp, json_t *obj, const char *path, const char *name);

void dm_docs_put_default(FILE *fp, json_t *obj);
void dm_docs_put_values (FILE *fp, json_t *obj);
void dm_docs_put_enum   (FILE *fp, json_t *obj);

bool dm_docs_is_object(json_t *obj);

const char *dm_docs_get_postfix_container(json_t *obj);
const char *dm_docs_get_postfix_item     (json_t *obj);

#endif
