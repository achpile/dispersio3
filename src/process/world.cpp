#include "meta/headers.hpp"


/***********************************************************************
     * ProcessWorld
     * constructor

***********************************************************************/
ach::ProcessWorld::ProcessWorld(ach::StateGame *_owner, ach::DataMap *_map) : Process(_owner)
{
	state     = ach::WorldState::wsFadeIn;
	map       = new ach::Map(this, _map);
	player    = new ach::Character(this, map->base->player, map->findMapSpawn(cache->spawn()));
	message   = new ach::Message(500.0f);
	status    = new ach::Status();
	arcade    = new ach::Cabinet();
	selection = new ach::LevelSelect(this, handler_game_pick);
	menu      = new ach::Menu(this, NULL, &theme->menu);

	map->cam->follow(&player->phys);
	map->characters.push_back(player);

	message->setPosition(sf::Vector2f(150.0f, 100.0f));

	menu->setPosition(sf::Vector2f(150, 310));
	menu->setWidthE(500);
	menu->setHeightE(300);

	fader.set(1.0f);

	fill();
}



/***********************************************************************
     * ProcessWorld
     * destructor

***********************************************************************/
ach::ProcessWorld::~ProcessWorld()
{
	delete map;
	delete menu;
	delete message;
	delete status;
	delete arcade;
	delete selection;
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
	cache->render();
}



/***********************************************************************
     * ProcessWorld
     * event

***********************************************************************/
void ach::ProcessWorld::event(sf::Event e)
{
	switch (state)
	{
		case ach::WorldState::wsPause:
			menu->event(e);
		break;


		case ach::WorldState::wsSelect:
			selection->event(e);
		break;


		case ach::WorldState::wsFadeIn:
		case ach::WorldState::wsFadeOut:
		case ach::WorldState::wsMessage:
		case ach::WorldState::wsArcade:
		case ach::WorldState::wsGame:
		break;
	}
}



/***********************************************************************
     * ProcessWorld
     * translate

***********************************************************************/
void ach::ProcessWorld::translate()
{
	menu->translate();
	status->translate();
	selection->translate();
}



/***********************************************************************
     * ProcessWorld
     * style

***********************************************************************/
void ach::ProcessWorld::style()
{
	message->style();
	status->style();
	selection->style();
	menu->style(&theme->menu);
}



/***********************************************************************
     * ProcessWorld
     * refresh

***********************************************************************/
void ach::ProcessWorld::refresh()
{
	map->refresh();
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
		break;


		case ach::WorldState::wsPause:
			tm->pause();
			menu->controls();
			menu->update();
		break;


		case ach::WorldState::wsSelect:
			tm->pause();
			selection->controls();
		break;


		case ach::WorldState::wsArcade:
			tm->pause();
			arcade->update();
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
			if (!fader.active())
				state = ach::WorldState::wsGame;
		break;


		case ach::WorldState::wsFadeOut:
			if (!fader.active())
				active = false;
		break;


		case ach::WorldState::wsMessage:
			message->render();

			if (ctrl->keys[ach::ControlAction::caMenu].pressed ||
			    ctrl->keys[ach::ControlAction::caJump].pressed)
				state = ach::WorldState::wsGame;
		break;


		case ach::WorldState::wsPause:
			status->render();
			menu->render();
		break;


		case ach::WorldState::wsSelect:
			selection->render();

			if (!selection->active)
			{
				app->mouse(false);
				state = ach::WorldState::wsGame;
			}
		break;


		case ach::WorldState::wsArcade:
			arcade->render();

			if (!arcade->active())
				state = ach::WorldState::wsGame;
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
	menu->init("UI.Menu.Main.InGame");

	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume"   , handler_game_resume , NULL));

	options_fill(menu, "UI.Menu.Main.InGame");

	if (cache->isRevert())
		menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, pair_get_string(cache->mode, pairLevelModeRevert), handler_game_revert, NULL));

	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.ExitGame" , handler_common_state, json_string("menu"    )));

	menu->finalize("UI.Menu.Misc.Resume");
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
	cache->goal();
}



/***********************************************************************
     * ProcessWorld
     * revert

***********************************************************************/
void ach::ProcessWorld::revert()
{
	state = ach::WorldState::wsFadeOut;

	fader.reset();
	cache->revert();
}



/***********************************************************************
     * ProcessWorld
     * warp

***********************************************************************/
void ach::ProcessWorld::warp(const char *map, const char *mode)
{
	state = ach::WorldState::wsFadeOut;

	fader.reset();
	cache->warp(map, pair_get_enum(mode, pairLevelMode), true);
}



/***********************************************************************
     * ProcessWorld
     * pause

***********************************************************************/
void ach::ProcessWorld::pause()
{
	state = ach::WorldState::wsPause;

	app->mouse(true);
	status->update();
}



/***********************************************************************
     * ProcessWorld
     * play

***********************************************************************/
void ach::ProcessWorld::play()
{
	state = ach::WorldState::wsArcade;

	arcade->init(false);
}



/***********************************************************************
     * ProcessWorld
     * select

***********************************************************************/
void ach::ProcessWorld::select(ach::LevelMode mode)
{
	state = ach::WorldState::wsSelect;

	app->mouse(true);
	selection->init(mode);
}



/***********************************************************************
     * ProcessWorld
     * notify

***********************************************************************/
void ach::ProcessWorld::notify(const char *msg)
{
	if (!msg)
		return;

	if (!strlen(msg))
		return;

	state = ach::WorldState::wsMessage;

	message->setString(lm->get(msg));
}
