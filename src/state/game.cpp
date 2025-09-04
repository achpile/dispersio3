#include "meta/headers.hpp"


/***********************************************************************
     * StateGame
     * constructor

***********************************************************************/
ach::StateGame::StateGame()
{
	create();

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
     * translate

***********************************************************************/
void ach::StateGame::translate()
{
	proc->translate();
}



/***********************************************************************
     * StateGame
     * style

***********************************************************************/
void ach::StateGame::style()
{
	proc->style();
}



/***********************************************************************
     * StateGame
     * create

***********************************************************************/
void ach::StateGame::create()
{
	switch (cache->state)
	{
		case ach::LevelState::lsIntro: proc = new ach::ProcessCutscene(this, cache->current->intro); break;
		case ach::LevelState::lsOutro: proc = new ach::ProcessCutscene(this, cache->current->outro); break;
		case ach::LevelState::lsLevel: proc = new ach::ProcessWorld   (this, cache->current       ); break;
	}
}



/***********************************************************************
     * StateGame
     * finish

***********************************************************************/
void ach::StateGame::finish()
{
	cache->next();

	if (cache->current->finish)
	{
		app->stateSet(ach::GameState::gsMenu);
		return;
	}

	delete proc;

	create();
}
