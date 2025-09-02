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
	selection = new ach::LevelSelect(this, handler_game_pick);
	menu      = new ach::Menu(this, NULL, &theme->menu);

	map->cam->follow(&player->phys);
	map->characters.push_back(player);

	message->setPosition(sf::Vector2f(150.0f, 100.0f));

	menu->setPosition(sf::Vector2f(150, 290));
	menu->setWidthE(500);
	menu->setHeightE(300);

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
	delete status;
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
		case ach::WorldState::wsGame:
		break;
	}
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
			message->render();

			if (ctrl->keys[ach::ControlAction::caMenu].released)
				state = ach::WorldState::wsGame;
		break;


		case ach::WorldState::wsPause:
			menu->render();
			status->render();
		break;


		case ach::WorldState::wsSelect:
			selection->render();

			if (!selection->active)
			{
				app->mouse(false);
				state = ach::WorldState::wsGame;
			}
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

	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume"   , handler_game_resume , NULL                   ));

	options_fill(menu, "UI.Menu.Main.InGame");

	if (cache->isReturn())
		menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Leave", NULL                , NULL                   ));

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
     * next

***********************************************************************/
void ach::ProcessWorld::next(const char *map)
{
	state = ach::WorldState::wsFadeOut;

	fader.reset();
	cache->select(map);
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
     * select

***********************************************************************/
void ach::ProcessWorld::select(ach::LevelMode type)
{
	state = ach::WorldState::wsSelect;

	app->mouse(true);
	selection->init(type);
}
