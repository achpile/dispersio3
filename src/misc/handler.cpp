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
}



/***********************************************************************
     * handlerState

***********************************************************************/
void handlerState(json_t *)
{
}
