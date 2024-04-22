#include "meta/headers.hpp"


/***********************************************************************
     * handlerLanguage

***********************************************************************/
void handlerLanguage(json_t *)
{
	lang->refresh();
	app->state->translate();
}



/***********************************************************************
     * handlerFullscreen

***********************************************************************/
void handlerFullscreen(json_t *)
{
	app->create();
}



/***********************************************************************
     * handlerAudio

***********************************************************************/
void handlerAudio(json_t *)
{
	sm->volume();
}



/***********************************************************************
     * handlerState

***********************************************************************/
void handlerState(json_t *data)
{
	app->stateSet((ach::GameState)pair_get_enum(json_string_value(data), pairGameState));
}



/***********************************************************************
     * handlerReset

***********************************************************************/
void handlerReset(json_t *)
{
	json_object_del(settings->data, "Control");
	json_dm_generate_default(settings->data, json_object_get(dm->dm, "Settings"));

	ctrl->init();
	ctrl->reset();
}
