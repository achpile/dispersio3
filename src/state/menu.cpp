#include "meta/headers.hpp"


/***********************************************************************
     * StateMenu
     * constructor

***********************************************************************/
ach::StateMenu::StateMenu()
{
	menu         = new ach::Menu(this, NULL, &theme->menu);
	training     = new ach::LevelSelect(this, handler_menu_pick);
	achievements = new ach::Achievements();
	leaderboards = new ach::Leaderboards();
	arcade       = new ach::Cabinet();
	state        = ach::MenuState::msMain;
	logo         = db->getSprite(json_object_get_branch_string(dm->data, "Meta.GFX.UI.Logo"))->spr;

	menu->setPosition(sf::Vector2f(150, 290));
	menu->setWidthE(500);
	menu->setHeightE(300);

	logo->spr->setPosition(RENDER_LAYER_GUI_X / 2, logo->tex->getSize().y / 2 + MENU_LOGO_OFFSET);

	fill();

	app->mouse(true);
	app->ignore();
	db->getTrack(json_object_get_branch_string(dm->data, "Meta.Track.Menu"))->play(true);
}



/***********************************************************************
     * StateMenu
     * destructor

***********************************************************************/
ach::StateMenu::~StateMenu()
{
	delete menu;
	delete training;
	delete arcade;
	delete achievements;
	delete leaderboards;
}



/***********************************************************************
     * StateMenu
     * update

***********************************************************************/
void ach::StateMenu::update()
{
	stars->update();

	prepare();
	render();
	finalize();
}



/***********************************************************************
     * StateMenu
     * render

***********************************************************************/
void ach::StateMenu::render()
{
	stars->render();

	rm->draw(logo->spr, ach::RenderLayer::rlGUI);

	draw();
}



/***********************************************************************
     * StateMenu
     * event

***********************************************************************/
void ach::StateMenu::event(sf::Event e)
{
	switch (state)
	{
		case ach::MenuState::msMain:
			menu->event(e);
		break;


		case ach::MenuState::msTraining:
			training->event(e);
		break;


		case ach::MenuState::msArcade:
		break;


		case ach::MenuState::msAchievements:
			achievements->event(e);
		break;


		case ach::MenuState::msLeaderboards:
			leaderboards->event(e);
		break;
	}
}



/***********************************************************************
     * StateMenu
     * translate

***********************************************************************/
void ach::StateMenu::translate()
{
	menu->translate();
	training->translate();
	achievements->translate();
	leaderboards->translate();
}



/***********************************************************************
     * StateMenu
     * style

***********************************************************************/
void ach::StateMenu::style()
{
	menu->style(&theme->menu);
	training->style();
	achievements->style();
	leaderboards->style();
}



/***********************************************************************
     * StateMenu
     * prepare

***********************************************************************/
void ach::StateMenu::prepare()
{
	switch (state)
	{
		case ach::MenuState::msMain:
			menu->controls();
			menu->update();
		break;


		case ach::MenuState::msTraining:
			training->controls();
			training->update();
		break;


		case ach::MenuState::msArcade:
			training->controls();
			arcade->update();
		break;


		case ach::MenuState::msAchievements:
			achievements->controls();
		break;


		case ach::MenuState::msLeaderboards:
			leaderboards->controls();
		break;
	}
}



/***********************************************************************
     * StateMenu
     * finalize

***********************************************************************/
void ach::StateMenu::finalize()
{
	switch (state)
	{
		case ach::MenuState::msMain:
		break;


		case ach::MenuState::msTraining:
			if (!training->active)
				state = ach::MenuState::msMain;
		break;


		case ach::MenuState::msArcade:
			if (!arcade->active())
				state = ach::MenuState::msMain;
		break;


		case ach::MenuState::msAchievements:
			if (!achievements->active)
				state = ach::MenuState::msMain;
		break;


		case ach::MenuState::msLeaderboards:
			if (!leaderboards->active)
				state = ach::MenuState::msMain;
		break;
	}
}



/***********************************************************************
     * StateMenu
     * draw

***********************************************************************/
void ach::StateMenu::draw()
{
	switch (state)
	{
		case ach::MenuState::msMain:
			menu->render();
		break;


		case ach::MenuState::msTraining:
			training->render();
		break;


		case ach::MenuState::msArcade:
			arcade->render();
		break;


		case ach::MenuState::msAchievements:
			achievements->render();
		break;


		case ach::MenuState::msLeaderboards:
			leaderboards->render();
		break;
	}
}



/***********************************************************************
     * StateMenu
     * fill

***********************************************************************/
void ach::StateMenu::fill()
{
	menu->init("UI.Menu.Main.Name");

	if (cache->isDefault() && !records->getAchievement(ach::Achievement::acEasy))
	{
		menu->add("UI.Menu.Main.Name"    , new ach::MenuItemFolder(menu, "UI.Menu.Play.Start"          ));
	}
	else
	{
		menu->add("UI.Menu.Main.Name"    , new ach::MenuItemFolder(menu, "UI.Menu.Play.Name"           ));

		if (!cache->isDefault())
			menu->add("UI.Menu.Play.Name", new ach::MenuItemAction(menu, "UI.Menu.Play.Continue"       , handler_menu_start        , json_pack("{s:b}"    , "New", false)));

		menu->add("UI.Menu.Play.Name"    , new ach::MenuItemFolder(menu, "UI.Menu.Play.Start"          ));

		if (records->getAchievement(ach::Achievement::acEasy))
		{
			menu->add("UI.Menu.Play.Name", new ach::MenuItemAction(menu, "UI.Menu.Play.Training"       , handler_menu_training     , NULL                                ));
			menu->add("UI.Menu.Play.Name", new ach::MenuItemAction(menu, "UI.Menu.Play.Arcade"         , handler_menu_arcade       , NULL                                ));
		}
	}

	menu->add("UI.Menu.Play.Start"       , new ach::MenuItemAction(menu, "UI.Menu.Play.Easy"           , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Difficulty", "easy"  )));
	menu->add("UI.Menu.Play.Start"       , new ach::MenuItemAction(menu, "UI.Menu.Play.Normal"         , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Difficulty", "normal")));
	menu->add("UI.Menu.Play.Start"       , new ach::MenuItemAction(menu, "UI.Menu.Play.Hard"           , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Difficulty", "hard"  )));

	options_fill(menu, "UI.Menu.Main.Name");

	menu->add("UI.Menu.Main.Name"        , new ach::MenuItemFolder(menu, "UI.Menu.Main.Records"        ));
	menu->add("UI.Menu.Main.Records"     , new ach::MenuItemAction(menu, "UI.Menu.Main.Achievements"   , handler_menu_achievements , NULL                                   ));
	menu->add("UI.Menu.Main.Records"     , new ach::MenuItemAction(menu, "UI.Menu.Main.Leaderboards"   , handler_menu_leaderboards , json_pack("{s:b}", "Highscores", false)));
	menu->add("UI.Menu.Main.Records"     , new ach::MenuItemAction(menu, "UI.Menu.Main.Highscores"     , handler_menu_leaderboards , json_pack("{s:b}", "Highscores", true )));

	menu->add("UI.Menu.Main.Name"        , new ach::MenuItemAction(menu, "UI.Menu.Main.Credits"        , handler_common_state      , json_string("credits")));
	menu->add("UI.Menu.Main.Name"        , new ach::MenuItemAction(menu, "UI.Menu.Misc.Exit"           , handler_common_state      , json_string("end"    )));

	menu->finalize(NULL);
}
