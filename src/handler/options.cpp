#include "meta/headers.hpp"


/***********************************************************************
     * handler_options_language

***********************************************************************/
void handler_options_language(void *, json_t *)
{
	lm->refresh();
	app->state->translate();
}



/***********************************************************************
     * handler_options_theme

***********************************************************************/
void handler_options_theme(void *, json_t *)
{
	theme->refresh();
	app->state->style();
}



/***********************************************************************
     * handler_options_fullscreen

***********************************************************************/
void handler_options_fullscreen(void *, json_t *)
{
	app->create();
}



/***********************************************************************
     * handler_options_smooth

***********************************************************************/
void handler_options_smooth(void *, json_t *)
{
	rm->setSmooth(settings->isSmooth());
}



/***********************************************************************
     * handler_options_audio

***********************************************************************/
void handler_options_audio(void *, json_t *)
{
	sm->volume();
	mm->volume();
}



/***********************************************************************
     * handler_options_reset

***********************************************************************/
void handler_options_reset(void *context, json_t *data)
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
