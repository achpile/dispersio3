#include "meta/headers.hpp"


/***********************************************************************
     * Tileset
     * constructor

***********************************************************************/
ach::Tileset::Tileset()
{
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
     * get

***********************************************************************/
ach::Tile* ach::Tileset::get(unsigned int id)
{
	if (!id)
		return NULL;

	for (unsigned int i = 1; i < tiles.size(); i++)
		if (tiles[i]->id == id)
			return tiles[i];

	return NULL;
}
