#include "meta/headers.hpp"


/***********************************************************************
     * StateFinish
     * constructor

***********************************************************************/
ach::StateFinish::StateFinish()
{
	app->stateSet(ach::GameState::gsMenu);
}



/***********************************************************************
     * StateFinish
     * destructor

***********************************************************************/
ach::StateFinish::~StateFinish()
{
}
