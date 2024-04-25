#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * load

***********************************************************************/
void ach::Map::load(const char *filename)
{
	json_error_t error;
	json_t *mapdata = json_load_file(filename, 0, &error);


	logger->log(ach::LogLevel::llInfo, "Loading map: \"%s\"", filename);

	if (!mapdata)
	{
		logger->log(ach::LogLevel::llError, "Error loading map: \"%s\" (%s)", filename, error.text);
		return;
	}


	char path[STR_LEN_PATH];
	strncpy(path, filename, STR_LEN_PATH);

	char *slash = strrchr(path, '/');

	if (!slash)
	{
		logger->log(ach::LogLevel::llError, "Filename does not seem ok: \"%s\"", filename);
		json_decref(mapdata);
		return;
	}

	*slash = 0;


	loadMeta(mapdata);
	loadInit();
	loadTileset(mapdata, path);

	json_decref(mapdata);
}



/***********************************************************************
     * Map
     * loadMeta

***********************************************************************/
void ach::Map::loadMeta(json_t *mapdata)
{
	size = sf::Vector2i(json_object_get_integer(mapdata, "width" ),
	                    json_object_get_integer(mapdata, "height"));
}



/***********************************************************************
     * Map
     * loadInit

***********************************************************************/
void ach::Map::loadInit()
{
	tiles = new ach::MapTile**[size.x];

	for (int x = 0; x < size.x; x++)
	{
		tiles[x] = new ach::MapTile*[size.y];

		for (int y = 0; y < size.y; y++)
			tiles[x][y] = new ach::MapTile();
	}
}



/***********************************************************************
     * Map
     * loadTileset

***********************************************************************/
void ach::Map::loadTileset(json_t *mapdata, const char *path)
{
	tileset = new ach::Tileset();

	json_t *item;
	size_t  index;

	json_array_foreach(json_object_get(mapdata, "tilesets"), index, item)
		tileset->load(path, item);

	tileset->sort();
}
