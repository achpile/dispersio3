#include "meta/headers.hpp"


/***********************************************************************
     * handlerLanguage

***********************************************************************/
void handlerLanguage(json_t *)
{
	lang->refresh();
	app->state->translate();
}
