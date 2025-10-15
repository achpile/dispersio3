#include "meta/headers.hpp"


/***********************************************************************
     * Checksum
     * constructor

***********************************************************************/
ach::Checksum::Checksum()
{
	load();

	check(FILE_CACHE);
}



/***********************************************************************
     * Checksum
     * destructor

***********************************************************************/
ach::Checksum::~Checksum()
{
	json_decref(data);
}



/***********************************************************************
     * Checksum
     * load

***********************************************************************/
void ach::Checksum::load()
{
	json_error_t error;

	data = json_load_file(FILE_CHECKSUM, 0, &error);

	if (!data)
		data = json_object();
}



/***********************************************************************
     * Checksum
     * save

***********************************************************************/
void ach::Checksum::save()
{
	json_dump_file(data, FILE_CHECKSUM, JSON_INDENT(4) | JSON_SORT_KEYS);
}



/***********************************************************************
     * Checksum
     * check

***********************************************************************/
void ach::Checksum::check(const char *path)
{
	if (!file_exists(path))
		return;

	if (!json_object_get(data, path))
	{
		unlink(path);
		return;
	}

	if (json_object_get_integer(data, path) != file_checksum(path))
	{
		unlink(path);
		logger->log(ach::LogLevel::llError, "Checksum mismatch: '%s'", path);
	}
}



/***********************************************************************
     * Checksum
     * store

***********************************************************************/
void ach::Checksum::store(const char *path)
{
	json_object_set_integer(data, path, file_checksum(path));

	save();
}
