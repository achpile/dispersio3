#include "meta/headers.hpp"


/***********************************************************************
     * handler_menu_start

***********************************************************************/
void handler_menu_start(void *, json_t *data)
{
	if (json_object_get_boolean(data, "New"))
		cache->reset(json_object_get_boolean(data, "Hard"));

	cache->init();

	app->stateSet(ach::GameState::gsGame);
}
