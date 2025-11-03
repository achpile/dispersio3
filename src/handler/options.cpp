#include "meta/headers.hpp"


/***********************************************************************
     * handler_options_language

***********************************************************************/
void handler_options_language(void *, json_t *)
{
	lm->refresh();
	app->state->translate();
	notify->translate();
}



/***********************************************************************
     * handler_options_theme

***********************************************************************/
void handler_options_theme(void *, json_t *)
{
	theme->refresh();
	app->state->style();
	cache->style();
	notify->style();
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
     * handler_options_framerate

***********************************************************************/
void handler_options_framerate(void *, json_t *)
{
	app->window->setFramerateLimit(settings->getFrameRate());
}



/***********************************************************************
     * handler_options_audio

***********************************************************************/
void handler_options_audio(void *, json_t *)
{
	sm->volume();
	mm->volume();
}
