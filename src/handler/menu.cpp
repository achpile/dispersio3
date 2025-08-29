#include "meta/headers.hpp"


/***********************************************************************
     * handler_menu_language

***********************************************************************/
void handler_menu_language(void *, json_t *)
{
	lm->refresh();
	app->state->translate();
}



/***********************************************************************
     * handler_menu_theme

***********************************************************************/
void handler_menu_theme(void *, json_t *)
{
	theme->refresh();
	app->state->style();
}



/***********************************************************************
     * handler_menu_fullscreen

***********************************************************************/
void handler_menu_fullscreen(void *, json_t *)
{
	app->create();
}



/***********************************************************************
     * handler_menu_smooth

***********************************************************************/
void handler_menu_smooth(void *, json_t *)
{
	rm->setSmooth(settings->isSmooth());
}



/***********************************************************************
     * handler_menu_audio

***********************************************************************/
void handler_menu_audio(void *, json_t *)
{
	sm->volume();
	mm->volume();
}



/***********************************************************************
     * handler_menu_state

***********************************************************************/
void handler_menu_state(void *, json_t *data)
{
	app->stateSet(pair_get_enum(json_string_value(data), pairGameState));
}



/***********************************************************************
     * handler_menu_start

***********************************************************************/
void handler_menu_start(void *, json_t *data)
{
	if (json_object_get_boolean(data, "New"))
		cache->reset(json_object_get_string(data, "Mode"));

	cache->init();

	app->stateSet(ach::GameState::gsGame);
}



/***********************************************************************
     * handler_menu_reset

***********************************************************************/
void handler_menu_reset(void *context, json_t *data)
{
	json_t     *action;
	const char *i;

	json_object_foreach(json_object_get(settings->data, "Control"), i, action)
		json_object_del(action, json_string_value(data));

	json_dm_generate_default(settings->data, json_object_get(dm->dm, "Settings"));

	ctrl->init();
	ctrl->reset();

	((ach::Menu*)context)->binder->init();
}
