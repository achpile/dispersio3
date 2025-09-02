#include "meta/headers.hpp"


/***********************************************************************
     * callback_level

***********************************************************************/
void callback_level(void *context, const char *name)
{
	if (!strstr(name, "Game.Map."))
	{
		((ach::LevelSelect*)context)->selected = NULL;
		return;
	}

	char map[STR_LEN_NAME];

	sscanf(name, "Game.Map.%[^.].Name", map);

	((ach::LevelSelect*)context)->selected = db->getMap(map);
	((ach::LevelSelect*)context)->update();
}



/***********************************************************************
     * handler_level_resume

***********************************************************************/
void handler_level_resume(void *context, json_t *)
{
	((ach::LevelSelect*)context)->active = false;
}



/***********************************************************************
     * handler_level_pick

***********************************************************************/
void handler_level_pick(void *context, json_t *data)
{
	((ach::LevelSelect*)context)->pick(data);
}
