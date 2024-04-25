#include "meta/headers.hpp"


/***********************************************************************
     * Tileset
     * constructor

***********************************************************************/
ach::Tileset::Tileset()
{
	tiles.push_back(NULL);
}



/***********************************************************************
     * Tileset
     * destructor

***********************************************************************/
ach::Tileset::~Tileset()
{
	listDelete(tiles);
}



/***********************************************************************
     * Tileset
     * load

***********************************************************************/
void ach::Tileset::load(const char *path, json_t *tileset)
{
	int first = json_object_get_integer(tileset, "firstgid");

	size_t  i;
	json_t *item;
	char    filename[STR_LEN_PATH];

	json_array_foreach(json_object_get(tileset, "tiles"), i, item)
	{
		snprintf(filename, STR_LEN_PATH, "%s/%s", path, json_object_get_string(item, "image"));
		tiles.push_back(new ach::Tile(filename, first + json_object_get_integer(item, "id")));
	}
}



/***********************************************************************
     * Tileset
     * sort

***********************************************************************/
void ach::Tileset::sort()
{
}
