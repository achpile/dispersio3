#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * load

***********************************************************************/
void ach::Map::load()
{
	json_error_t error;
	json_t *mapdata = json_load_file(base->filename, 0, &error);


	logger->log(ach::LogLevel::llInfo, "Loading map: \"%s\"", base->filename);

	if (!mapdata)
	{
		logger->log(ach::LogLevel::llError, "Error loading map: \"%s\" (%s)", base->filename, error.text);
		return;
	}


	char path[STR_LEN_PATH];
	strncpy(path, base->filename, STR_LEN_PATH);

	char *slash = strrchr(path, '/');

	if (!slash)
	{
		logger->log(ach::LogLevel::llError, "Filename does not seem ok: \"%s\"", base->filename);
		json_decref(mapdata);
		return;
	}

	*slash = 0;


	loadMeta(mapdata);
	loadInit();
	loadTileset(mapdata, path);
	loadLayers(mapdata);
	loadFinalize();

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

	spawn    = getTileRect(base->spawn);
}



/***********************************************************************
     * Map
     * loadFinalize

***********************************************************************/
void ach::Map::loadFinalize()
{
	areas.push_back(new ach::MapArea(sf::FloatRect(sf::Vector2f(0, 0), vector_mult(sizeMap, sizeTile))));

	list_foreach(objects)
	{
		objects[i]->reset();
		objects[i]->init(this);
	}

	size_t  i;
	json_t *index;

	ach::MapObject *item;

	json_array_foreach(json_object_get(cache->info, "Item"), i, index)
	{
		item = findMapObject(json_integer_value(index));

		if (item)
			item->alive = false;
	}
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
	ach::TileLayer tl = pair_get_enum(json_object_get_string(layer, "name"), pairTileLayer);

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
		     if (!strcmp(json_object_get_string(layer, "name"), "phys"      )) loadPhys      (layer);
		else if (!strcmp(json_object_get_string(layer, "name"), "objects"   )) loadObjects   (layer);
		else if (!strcmp(json_object_get_string(layer, "name"), "characters")) loadCharacters(layer);
		else if (!strcmp(json_object_get_string(layer, "name"), "camera"    )) loadCamera    (layer);

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
		type = pair_get_enum(json_object_get_string(obj, "type"), pairPhysType);

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
		     if (!strcmp(json_object_get_string(obj, "type"), "obj_decor"      )) objects.push_back(new ach::MapObjectDecor      (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "obj_door"       )) objects.push_back(new ach::MapObjectDoor       (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "obj_level"      )) objects.push_back(new ach::MapObjectLevel      (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "obj_arcade"     )) objects.push_back(new ach::MapObjectArcade     (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "obj_checkpoint" )) objects.push_back(new ach::MapObjectCheckpoint (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "obj_points"     )) objects.push_back(new ach::MapObjectPoints     (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "obj_item"       )) objects.push_back(new ach::MapObjectItem       (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "obj_npc"        )) objects.push_back(new ach::MapObjectNPC        (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "obj_antigrav"   )) objects.push_back(new ach::MapObjectAntigrav   (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "block_moving"   )) objects.push_back(new ach::MapObjectMoving     (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "block_fragile"  )) objects.push_back(new ach::MapObjectFragile    (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "block_break"    )) objects.push_back(new ach::MapObjectBreak      (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "block_yoku"     )) objects.push_back(new ach::MapObjectYoku       (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "block_gate"     )) objects.push_back(new ach::MapObjectGate       (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "trigger_goal"   )) objects.push_back(new ach::MapObjectGoal       (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "trigger_water"  )) objects.push_back(new ach::MapObjectWater      (world, obj));
		else if (!strcmp(json_object_get_string(obj, "type"), "trigger_wind"   )) objects.push_back(new ach::MapObjectWind       (world, obj));

		else logger->log(ach::LogLevel::llWarning, "Unknown map object type \"%s\"", json_object_get_string(obj, "type"));
	}
}



/***********************************************************************
     * Map
     * loadCharacters

***********************************************************************/
void ach::Map::loadCharacters(json_t *layer)
{
	json_t *obj;
	size_t  index;

	json_array_foreach(json_object_get(layer, "objects"), index, obj)
	{
		if (strcmp(json_object_get_string(obj, "type"), "character") != 0)
		{
			logger->log(ach::LogLevel::llWarning, "Expected character instead of \"%s\"", json_object_get_string(obj, "type"));
			continue;
		}

		characters.push_back(new ach::Character(world, obj));
	}
}



/***********************************************************************
     * Map
     * loadCamera

***********************************************************************/
void ach::Map::loadCamera(json_t *layer)
{
	json_t *obj;
	size_t  index;

	json_array_foreach(json_object_get(layer, "objects"), index, obj)
	{
		if (strcmp(json_object_get_string(obj, "type"), "area") != 0)
		{
			logger->log(ach::LogLevel::llWarning, "Expected area instead of \"%s\"", json_object_get_string(obj, "type"));
			continue;
		}

		areas.push_back(new ach::MapArea(obj));
	}
}
