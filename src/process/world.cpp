#include "meta/headers.hpp"


/***********************************************************************
     * ProcessWorld
     * constructor

***********************************************************************/
ach::ProcessWorld::ProcessWorld(ach::StateGame *_owner, ach::DataMap *_map) : Process(_owner)
{
	state   = ach::WorldState::wsFadeIn;
	map     = new ach::Map(this, _map);
	player  = new ach::Character(this, map->base->player, map->findMapSpawn(cache->spawn()));
	message = new ach::Message(500.0f);
	menu    = new ach::Menu(this, &theme->menu);

	map->cam->follow(&player->phys);
	map->characters.push_back(player);

	message->setPosition(sf::Vector2f(150.0f, 100.0f));

	menu->setPosition(sf::Vector2f(200, 250));
	menu->setWidth(400);
	menu->setHeight(10);

	mm->play(map->base->track);

	fader.set(1.0f);

	fill();
}



/***********************************************************************
     * ProcessWorld
     * destructor

***********************************************************************/
ach::ProcessWorld::~ProcessWorld()
{
	rm->reset();

	delete map;
	delete menu;
	delete message;
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
     * StateMenu
     * event

***********************************************************************/
void ach::ProcessWorld::event(sf::Event e)
{
	if (state == ach::WorldState::wsPause)
		menu->event(e);
}



/***********************************************************************
     * ProcessWorld
     * translate

***********************************************************************/
void ach::ProcessWorld::translate()
{
	menu->translate();
}



/***********************************************************************
     * ProcessWorld
     * style

***********************************************************************/
void ach::ProcessWorld::style()
{
	message->style();
	menu->style(&theme->menu);
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


		case ach::WorldState::wsMessage:
			tm->pause();
			message->render();
		break;


		case ach::WorldState::wsPause:
			tm->pause();
			menu->controls();
			menu->update();
		break;


		case ach::WorldState::wsGame:
			cache->update();
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
				owner->finish();
		break;


		case ach::WorldState::wsMessage:
			if (ctrl->keys[ach::ControlAction::caMenu].released)
				state = ach::WorldState::wsGame;
		break;


		case ach::WorldState::wsPause:
			menu->render();
		break;


		case ach::WorldState::wsGame:
		break;
	}
}



/***********************************************************************
     * ProcessWorld
     * fill

***********************************************************************/
void ach::ProcessWorld::fill()
{
	menu->init("Main.InGame");

	menu->add("Main.InGame", new ach::MenuItemAction(menu, "Misc.Resume"   , handler_game_resume , NULL                   ));

	options_fill(menu, "Main.InGame");

	if (cache->canReturn())
		menu->add("Main.InGame", new ach::MenuItemAction(menu, "Misc.Leave", NULL                , NULL                   ));

	menu->add("Main.InGame", new ach::MenuItemAction(menu, "Misc.ExitGame" , handler_common_state, json_string("menu"    )));

	menu->finalize();
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



/***********************************************************************
     * ProcessWorld
     * pause

***********************************************************************/
void ach::ProcessWorld::pause()
{
	state = ach::WorldState::wsPause;

	app->mouse(true);
}
