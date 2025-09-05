#include "meta/headers.hpp"


/***********************************************************************
     * handler_menu_start

***********************************************************************/
void handler_menu_start(void *, json_t *data)
{
	if (json_object_get_boolean(data, "New"))
		cache->reset(pair_get_enum(json_object_get_string(data, "Difficulty"), pairDifficulty));

	cache->init();

	app->stateSet(ach::GameState::gsGame);
}
