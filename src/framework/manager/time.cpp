#include "meta/headers.hpp"


/***********************************************************************
     * TimeManager
     * constructor

***********************************************************************/
ach::TimeManager::TimeManager()
{
	clock = new sf::Clock();

	init();
}



/***********************************************************************
     * TimeManager
     * destructor

***********************************************************************/
ach::TimeManager::~TimeManager()
{
	delete clock;
}



/***********************************************************************
     * TimeManager
     * init

***********************************************************************/
void ach::TimeManager::init()
{
	last   = clock->getElapsedTime().asMilliseconds();
	passed = 0.0f;
}



/***********************************************************************
     * TimeManager
     * update

***********************************************************************/
void ach::TimeManager::update()
{
	long current = clock->getElapsedTime().asMilliseconds();

	frame   = (current - last) / 1000.0;
	real    = frame;
	last    = current;
	passed += frame;
}



/***********************************************************************
     * TimeManager
     * get

***********************************************************************/
float ach::TimeManager::get(ach::TimeSource source)
{
	switch (source)
	{
		case ach::TimeSource::tsReal : return real;
		case ach::TimeSource::tsFrame: return frame;

		default                      : return 0.0f;
	}
}
