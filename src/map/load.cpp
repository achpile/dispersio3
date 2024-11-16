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
	loadLayers(mapdata);

	json_decref(mapdata);
}



/***********************************************************************
     * Map
     * loadMeta

***********************************************************************/
void ach::Map::loadMeta(json_t *mapdata)
{
	sizeMap  = sf::Vector2i(json_object_get_integer(mapdata, "width" ),
	                        json_object_get_integer(mapdata, "height"));

	sizeTile = sf::Vector2i(json_object_get_integer(mapdata, "tilewidth" ),
	                        json_object_get_integer(mapdata, "tileheight"));

	spawn = getTileCenter(sf::Vector2i(json_property_get_integer(mapdata, "spawnX"),
	                                   json_property_get_integer(mapdata, "spawnY")));
}



/***********************************************************************
     * Map
     * loadInit

***********************************************************************/
void ach::Map::loadInit()
{
	tiles = new ach::MapTile**[sizeMap.x];

	for (int x = 0; x < sizeMap.x; x++)
	{
		tiles[x] = new ach::MapTile*[sizeMap.y];

		for (int y = 0; y < sizeMap.y; y++)
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
}



/***********************************************************************
     * Map
     * loadLayers

***********************************************************************/
void ach::Map::loadLayers(json_t *mapdata)
{
	json_t *layer;
	size_t  index;

	json_array_foreach(json_object_get(mapdata, "layers"), index, layer)
	{
		     if (!strcmp(json_object_get_string(layer, "type"), "tilelayer"  )) loadLayerTiles  (layer);
		else if (!strcmp(json_object_get_string(layer, "type"), "objectgroup")) loadLayerObjects(layer);

		else logger->log(ach::LogLevel::llWarning, "Unknown map layer type \"%s\"", json_object_get_string(layer, "type"));
	}
}



/***********************************************************************
     * Map
     * loadLayerTiles

***********************************************************************/
void ach::Map::loadLayerTiles(json_t *layer)
{
	ach::TileLayer tl = (ach::TileLayer)pair_get_enum(json_object_get_string(layer, "name"), pairTileLayer);

	for (int x = 0; x < sizeMap.x; x++)
		for (int y = 0; y < sizeMap.y; y++)
			tiles[x][y]->set(tileset->get(json_integer_value(json_array_get(json_object_get(layer, "data"), x + y * sizeMap.x))), tl);
}



/***********************************************************************
     * Map
     * loadLayerObjects

***********************************************************************/
void ach::Map::loadLayerObjects(json_t *layer)
{
		     if (!strcmp(json_object_get_string(layer, "name"), "phys"   )) loadPhys   (layer);
		else if (!strcmp(json_object_get_string(layer, "name"), "objects")) loadObjects(layer);

		else logger->log(ach::LogLevel::llWarning, "Unknown map layer \"%s\"", json_object_get_string(layer, "name"));
}



/***********************************************************************
     * Map
     * loadPhys

***********************************************************************/
void ach::Map::loadPhys(json_t *layer)
{
	ach::PhysType type;

	sf::Vector2f  pos;
	sf::Vector2f  a, b;

	json_t *obj, *coord;
	size_t  index, i;


	json_array_foreach(json_object_get(layer, "objects"), index, obj)
	{
		pos  = vector_json_coord(obj);
		type = (ach::PhysType)pair_get_enum(json_object_get_string(obj, "type"), pairPhysType);

		json_array_foreach(json_object_get(obj, "polyline"), i, coord)
		{
			a = b;
			b = vector_json_coord(coord);

			if (i)
				collision->lines.push_back(new ach::PhysLine(type, a, b, pos));
		}
	}

	collision->split(vector_mult_i(sizeMap, sizeTile));
}



/***********************************************************************
     * Map
     * loadObjects

***********************************************************************/
void ach::Map::loadObjects(json_t *layer)
{
	json_t *obj;
	size_t  index;

	json_array_foreach(json_object_get(layer, "objects"), index, obj)
	{
		     if (!strcmp(json_object_get_string(obj, "type"), "decor")) objects.push_back(new ach::MapObjectDecor(obj));

		else logger->log(ach::LogLevel::llWarning, "Unknown map object type \"%s\"", json_object_get_string(layer, "type"));
	}
}
