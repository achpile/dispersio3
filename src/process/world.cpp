#include "meta/headers.hpp"


/***********************************************************************
     * ProcessWorld
     * constructor

***********************************************************************/
ach::ProcessWorld::ProcessWorld(ach::StateGame *_owner) : Process(_owner)
{
	state  = ach::WorldState::wsFadeIn;
	map    = new ach::Map(this, db->getMap("Default"));
	player = new ach::Character(this, map->base->player, map->spawn);

	map->cam->follow(&player->phys);
	map->characters.push_back(player);

	mm->play(map->base->track);

	fader.set(1.0f);
}



/***********************************************************************
     * ProcessWorld
     * destructor

***********************************************************************/
ach::ProcessWorld::~ProcessWorld()
{
	rm->reset();

	delete map;
}



/***********************************************************************
     * ProcessWorld
     * update

***********************************************************************/
void ach::ProcessWorld::update()
{
	prepare();
	render();
	finalize();
}



/***********************************************************************
     * ProcessWorld
     * render

***********************************************************************/
void ach::ProcessWorld::render()
{
	map->render();
}



/***********************************************************************
     * ProcessWorld
     * prepare

***********************************************************************/
void ach::ProcessWorld::prepare()
{
	switch (state)
	{
		case ach::WorldState::wsFadeIn:
			tm->pause();
			fader.update(true);
			rm->setFade(fader.progress());
		break;


		case ach::WorldState::wsFadeOut:
			tm->pause();
			fader.update(true);
			rm->setFade(fader.progress(true));
		break;


		case ach::WorldState::wsGame:
			map->update();
			map->touch(player);
		break;
	}
}



/***********************************************************************
     * ProcessWorld
     * finalize

***********************************************************************/
void ach::ProcessWorld::finalize()
{
	switch (state)
	{
		case ach::WorldState::wsFadeIn:
			if (!fader.isActive())
			{
				state = ach::WorldState::wsGame;
				rm->reset();
			}
		break;


		case ach::WorldState::wsFadeOut:
			if (!fader.isActive())
				owner->next();
		break;


		case ach::WorldState::wsGame:
		break;
	}
}



/***********************************************************************
     * ProcessWorld
     * gateway

***********************************************************************/
void ach::ProcessWorld::gateway(sf::FloatRect dest)
{
	player->gateway(dest);
	map->cam->update();
}



/***********************************************************************
     * ProcessWorld
     * goal

***********************************************************************/
void ach::ProcessWorld::goal()
{
	state = ach::WorldState::wsFadeOut;

	fader.reset();
}
