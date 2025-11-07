#include "meta/headers.hpp"


/***********************************************************************
     * file_is_regular

***********************************************************************/
bool file_is_regular(const char *path)
{
	struct stat st;
	stat(path, &st);

	return S_ISREG(st.st_mode);
}



/***********************************************************************
     * file_is_directory

***********************************************************************/
bool file_is_directory(const char *path)
{
	struct stat st;
	stat(path, &st);

	return S_ISDIR(st.st_mode);
}



/***********************************************************************
     * file_checksum

***********************************************************************/
uint32_t file_checksum(const char *path)
{
	FILE *fp = fopen(path, "rb");

	if (!fp)
		return 0;

	uint16_t a = 1;
	uint16_t b = 0;
	uint8_t  c;

	while (fread(&c, 1, 1, fp))
	{
		a += c;
		b += a;
	}

	fclose(fp);

	return a + (b << 16);
}



/***********************************************************************
     * file_erase

***********************************************************************/
void file_erase(const char *path)
{
	json_t *obj = json_object();

	json_dump_file(obj, path, JSON_INDENT(4) | JSON_SORT_KEYS);

	json_decref(obj);
}
