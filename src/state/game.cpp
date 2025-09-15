#include "meta/headers.hpp"


/***********************************************************************
     * StateGame
     * constructor

***********************************************************************/
ach::StateGame::StateGame()
{
	proc = NULL;

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

	if (!proc->active)
		finish();
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
	if (proc)
		delete proc;

	switch (cache->state)
	{
		case ach::LevelState::lsIntro: proc = new ach::ProcessCutscene(this, cache->current->intro); break;
		case ach::LevelState::lsOutro: proc = new ach::ProcessCutscene(this, cache->current->outro); break;
		case ach::LevelState::lsLevel: proc = new ach::ProcessWorld   (this, cache->current       ); break;
	}

	cache->process = proc;
}



/***********************************************************************
     * StateGame
     * finish

***********************************************************************/
void ach::StateGame::finish()
{
	if (cache->finished)
	{
		if (cache->mode == ach::LevelMode::lmTraining)
			app->stateSet(ach::GameState::gsMenu);
		else
			app->stateSet(ach::GameState::gsFinish);

		return;
	}

	create();
}
