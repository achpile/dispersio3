#include "meta/headers.hpp"


/***********************************************************************
     * dm_docs_generate

***********************************************************************/
void dm_docs_generate(json_t *obj, const char *filename)
{
	FILE *fp = fopen(filename, "w");

	if (!fp)
	{
		logger->log(ach::LogLevel::llError, "Error opening file: '%s'", DM_DOCS_FILE_OUTPUT);
		return;
	}

	dm_docs_generate_header(fp);
	dm_docs_generate_contents(fp, obj);
	dm_docs_generate_table(fp, obj);
	dm_docs_generate_footer(fp);

	fclose(fp);
}



/***********************************************************************
     * dm_docs_generate_header

***********************************************************************/
void dm_docs_generate_header(FILE *fp)
{
	html_start(fp);

	html_head_start(fp);
	html_include_css(fp, DM_DOCS_FILE_STYLE);
	html_title(fp, PROJECT_NAME " datamodel documentation");
	html_head_end(fp);

	html_body_start(fp);
	html_section_header(fp, PROJECT_NAME " datamodel documentation");
}



/***********************************************************************
     * dm_docs_generate_contents

***********************************************************************/
void dm_docs_generate_contents(FILE *fp, json_t *obj)
{
	html_section_subheader(fp, "Contents");
	html_list_start(fp);

	dm_docs_generate_recursive(fp, obj, true, "", "", true);

	html_list_end(fp);
}



/***********************************************************************
     * dm_docs_generate_table

***********************************************************************/
void dm_docs_generate_table(FILE *fp, json_t *obj)
{
	html_section_subheader(fp, "Datamodel");

	html_table_start(fp);
	html_table_row_start(fp, "");

	html_table_header(fp, "20", "Name"         );
	html_table_header(fp, "10", "Type"         );
	html_table_header(fp, "10", "Values"       );
	html_table_header(fp, "10", "Default value");

	html_table_row_end(fp);

	dm_docs_generate_recursive(fp, obj, false, "", "", true);

	html_table_end(fp);
}



/***********************************************************************
     * dm_docs_generate_footer

***********************************************************************/
void dm_docs_generate_footer(FILE *fp)
{
	html_body_end(fp);
	html_end(fp);
}



/***********************************************************************
     * dm_docs_generate_recursive

***********************************************************************/
void dm_docs_generate_recursive(FILE *fp, json_t *obj, bool listing, const char *path, const char *name, bool skip)
{
	char current[STR_LEN_PATH] = {0};

	if (!skip)
	{
		snprintf(current, STR_LEN_PATH, "%s%s%s", path, name, dm_docs_get_postfix(obj));

		if (listing) dm_docs_generate_item_link(fp,      current      );
		else         dm_docs_generate_item_row (fp, obj, current, name);
	}
/* TODO
	if (!json_attr_get_container(obj))
		return;
*/
	dm_docs_generate_foreach(fp, obj, listing, current, false);
	dm_docs_generate_foreach(fp, obj, listing, current, true );
}



/***********************************************************************
     * dm_docs_generate_foreach

***********************************************************************/
void dm_docs_generate_foreach(FILE *fp, json_t *obj, bool listing, const char *current, bool container)
{
	json_t     *i;
	const char *key;

	json_object_foreach(obj, key, i)
	{
		if (!strcmp(key, DM_DIRECTIVE_ATTR))
			continue;

(void)container;
/* TODO
		if (json_attr_get_container(i) != container)
			continue;
*/
		dm_docs_generate_recursive(fp, i, listing, current, key, false);
	}
}



/***********************************************************************
     * dm_docs_generate_item_link

***********************************************************************/
void dm_docs_generate_item_link(FILE *fp, const char *path)
{
	html_list_item_start(fp);
	html_link_add(fp, path);
	html_list_item_end(fp);
}



/***********************************************************************
     * dm_docs_generate_item_row

***********************************************************************/
void dm_docs_generate_item_row(FILE *fp, json_t *obj, const char *path, const char *name)
{

(void)path;
(void)name;
/* TODO
	html_table_row_start(fp, json_attr_get_container(obj) ? "o" : "");

	html_table_data_start(fp);
	html_link_set(fp, path, json_attr_get_container(obj) ? path : name);
	html_table_data_end(fp);
*/

	html_table_data_start(fp);
	fprintf(fp, "%s", json_attr_get_type_raw(obj));
	html_table_data_end(fp);

	html_table_data_start(fp);
	dm_docs_put_values(fp, obj);
	html_table_data_end(fp);

	html_table_data_start(fp);
	dm_docs_put_default(fp, obj);
	html_table_data_end(fp);

	html_table_row_end(fp);
}



/***********************************************************************
     * dm_docs_get_postfix

***********************************************************************/
const char *dm_docs_get_postfix(json_t *obj)
{
	switch (json_attr_get_type(obj))
	{
		case ach::DataType::dtObject  : return ".";
		case ach::DataType::dtArray   : return ".[i].";
		case ach::DataType::dtMulti   : return ".{i}.";

		case ach::DataType::dtString  :
		case ach::DataType::dtInteger :
		case ach::DataType::dtReal    :
		case ach::DataType::dtBoolean :
		case ach::DataType::dtFilename:
		case ach::DataType::dtColor   :
		case ach::DataType::dtLink    :
		case ach::DataType::dtEnum    :
		case ach::DataType::dtUnknown : return "";
	}

	return "";
}



/***********************************************************************
     * dm_docs_put_default

***********************************************************************/
void dm_docs_put_default(FILE *fp, json_t *obj)
{
	switch (json_attr_get_type(obj))
	{
		case ach::DataType::dtObject  : fprintf(fp, "-"); break;
		case ach::DataType::dtArray   : fprintf(fp, "-"); break;
		case ach::DataType::dtMulti   : fprintf(fp, "-"); break;
		case ach::DataType::dtString  : fprintf(fp, "%s"  , json_string_value (json_attr_get_default(obj))); break;
		case ach::DataType::dtInteger : fprintf(fp, "%lld", json_integer_value(json_attr_get_default(obj))); break;
		case ach::DataType::dtReal    : fprintf(fp, "%.3f", json_real_value   (json_attr_get_default(obj))); break;
		case ach::DataType::dtBoolean : fprintf(fp, "%s"  , json_is_true      (json_attr_get_default(obj)) ? "true" : "false"); break;
		case ach::DataType::dtFilename: fprintf(fp, "%s"  , json_string_value (json_attr_get_default(obj))); break;
		case ach::DataType::dtColor   : fprintf(fp, "%s"  , json_string_value (json_attr_get_default(obj))); break;
		case ach::DataType::dtLink    : fprintf(fp, "%s"  , json_string_value (json_attr_get_default(obj))); break;
		case ach::DataType::dtEnum    : fprintf(fp, "%s"  , json_string_value (json_attr_get_default(obj))); break;
		case ach::DataType::dtUnknown : break;
	}
}



/***********************************************************************
     * dm_docs_put_values

***********************************************************************/
void dm_docs_put_values(FILE *fp, json_t *obj)
{
	switch (json_attr_get_type(obj))
	{
		case ach::DataType::dtObject  : fprintf(fp, "-"           ); break;
		case ach::DataType::dtArray   : fprintf(fp, "-"           ); break;
		case ach::DataType::dtMulti   : fprintf(fp, "-"           ); break;
		case ach::DataType::dtBoolean : fprintf(fp, "true/false"  ); break;
		case ach::DataType::dtColor   : fprintf(fp, "#rrggbb(aa)" ); break;
		case ach::DataType::dtFilename: fprintf(fp, "(%d)"        , STR_LEN_PATH               ); break;
		case ach::DataType::dtString  : fprintf(fp, "(%lu)"       , json_attr_get_maxlen  (obj)); break;
		case ach::DataType::dtLink    : fprintf(fp, "Object in %s", json_attr_get_data    (obj)); break;
		case ach::DataType::dtInteger : fprintf(fp, "[%d..%d]"    , json_attr_get_min     (obj), json_attr_get_max     (obj)); break;
		case ach::DataType::dtReal    : fprintf(fp, "[%.3f..%.3f]", json_attr_get_min_real(obj), json_attr_get_max_real(obj)); break;
		case ach::DataType::dtEnum    : html_list_start(fp);        dm_docs_put_enum(fp, obj);   html_list_end(fp);            break;
		case ach::DataType::dtUnknown : break;
	}
}



/***********************************************************************
     * dm_docs_put_enum

***********************************************************************/
void dm_docs_put_enum(FILE *fp, json_t *obj)
{
	size_t  index;
	json_t *item;

	json_array_foreach(json_attr_get_enum(obj), index, item)
	{
		html_list_item_start(fp);
		fprintf(fp, "%s", json_string_value(item));
		html_list_item_end(fp);
	}
}
