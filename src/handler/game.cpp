#include "meta/headers.hpp"


/***********************************************************************
     * handler_game_resume

***********************************************************************/
void handler_game_resume(void *context, json_t *)
{
	app->mouse(false);

	((ach::ProcessWorld*)context)->state = ach::WorldState::wsGame;
	((ach::ProcessWorld*)context)->menu->reset();
}



/***********************************************************************
     * handler_game_revert

***********************************************************************/
void handler_game_revert(void *context, json_t *)
{
	((ach::ProcessWorld*)context)->revert();
}



/***********************************************************************
     * handler_game_pick

***********************************************************************/
void handler_game_pick(void *context, json_t *data)
{
	((ach::ProcessWorld*)context)->warp(json_object_get_string(data, "Map"), json_object_get_string(data, "Mode"));
}
