#include "meta/headers.hpp"


/***********************************************************************
     * StateGame
     * constructor

***********************************************************************/
ach::StateGame::StateGame()
{
	proc = new ach::ProcessWorld(this, cache->current);

	app->mouse(false);
}



/***********************************************************************
     * StateGame
     * destructor

***********************************************************************/
ach::StateGame::~StateGame()
{
	delete proc;
}



/***********************************************************************
     * StateGame
     * update

***********************************************************************/
void ach::StateGame::update()
{
	stars->update();
	stars->render();

	proc->update();
}



/***********************************************************************
     * StateGame
     * event

***********************************************************************/
void ach::StateGame::event(sf::Event e)
{
	proc->event(e);
}



/***********************************************************************
     * StateGame
     * finish

***********************************************************************/
void ach::StateGame::finish()
{
	if (cache->current->finish)
	{
		app->stateSet(ach::GameState::gsMenu);
		return;
	}

	cache->finish();

	delete proc;

	proc = new ach::ProcessWorld(this, cache->current);
}
