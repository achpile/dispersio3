#include "meta/headers.hpp"


/***********************************************************************
     * handler_game_resume

***********************************************************************/
void handler_game_resume(void *context, json_t *)
{
	app->mouse(false);

	((ach::ProcessWorld*)context)->state = ach::WorldState::wsGame;
}
