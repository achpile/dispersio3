#ifndef __FRAMEWORK_JSON_MACROS
#define __FRAMEWORK_JSON_MACROS


#define json_object_get_integer(obj, name) json_integer_value(json_object_get(obj, name))
#define json_object_get_string(obj, name)  json_string_value (json_object_get(obj, name))
#define json_object_get_boolean(obj, name) json_is_true(json_object_get(obj, name))

#define json_object_get_branch_integer(obj, name) json_integer_value(json_object_get_branch(obj, name))
#define json_object_get_branch_string(obj, name)  json_string_value (json_object_get_branch(obj, name))
#define json_object_get_branch_boolean(obj, name) json_boolean_value(json_object_get_branch(obj, name))

#define json_object_set_integer(obj, name, val)  json_object_set_new(obj, name, json_integer(val))
#define json_object_set_string(obj, name, val)   json_object_set_new(obj, name, json_string (val))
#define json_object_set_boolean(obj, name, val)  json_object_set_new(obj, name, json_boolean(val))

#define json_object_set_branch_integer(obj, path, val)  json_object_set_branch(obj, path, json_integer(val))
#define json_object_set_branch_string(obj, path, val)   json_object_set_branch(obj, path, json_string (val))
#define json_object_set_branch_boolean(obj, path, val)  json_object_set_branch(obj, path, json_boolean(val))

#endif
