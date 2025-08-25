#ifndef __FRAMEWORK_DATAMODEL_PREPROCESSOR
#define __FRAMEWORK_DATAMODEL_PREPROCESSOR


json_t     *json_preprocess(json_t *obj, const char *dir);
json_t     *json_preprocess_directive(const char *name, const char *dir);
json_t     *json_preprocess_include(const char *name, const char *dir, bool silent);
json_t     *json_preprocess_dir(const char *name, const char *dir, bool recursive);
const char *json_preprocess_argument(const char *str);

#endif
