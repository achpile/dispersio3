#include "meta/app.hpp"


/***********************************************************************
     * App
     * constructor

***********************************************************************/
ach::App::App()
{
	isRunning = true;
}



/***********************************************************************
     * App
     * destructor

***********************************************************************/
ach::App::~App()
{
}



/***********************************************************************
     * App
     * update

***********************************************************************/
void ach::App::update()
{
	isRunning = false;
}
