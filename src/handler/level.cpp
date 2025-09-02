#include "meta/headers.hpp"


/***********************************************************************
     * callback_level

***********************************************************************/
void callback_level(void *context, const char *name)
{
	char map[STR_LEN_NAME];

	sscanf(name, "Game.Map.%[^.].Name", map);

	((ach::LevelSelect*)context)->selected = db->getMap(map);
	((ach::LevelSelect*)context)->update();
}
