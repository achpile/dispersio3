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
     * pause

***********************************************************************/
void ach::TimeManager::pause()
{
	frame = 0.0f;
}



/***********************************************************************
     * TimeManager
     * get

***********************************************************************/
float ach::TimeManager::get(bool isReal)
{
	return isReal ? real : frame;
}
