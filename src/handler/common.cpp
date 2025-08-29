#include "meta/headers.hpp"


/***********************************************************************
     * handler_common_state

***********************************************************************/
void handler_common_state(void *, json_t *data)
{
	app->stateSet(pair_get_enum(json_string_value(data), pairGameState));
}



