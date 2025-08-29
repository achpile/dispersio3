#include "meta/headers.hpp"


/***********************************************************************
     * StateMenu
     * constructor

***********************************************************************/
ach::StateMenu::StateMenu()
{
	menu = new ach::Menu(NULL, &theme->menu);

	menu->setPosition(sf::Vector2f(200, 250));
	menu->setWidth(400);
	menu->setHeight(10);

	logo = new ach::Sprite(json_object_get_branch_string(dm->data, "Meta.GFX.Logo"), false, true);

	logo->spr->setPosition(RENDER_LAYER_GUI_X / 2, logo->tex->getSize().y / 2 + MENU_LOGO_OFFSET);

	fill();

	app->mouse(true);
	mm->play(json_object_get_branch_string(dm->data, "Meta.Track.Menu"));
}



/***********************************************************************
     * StateMenu
     * destructor

***********************************************************************/
ach::StateMenu::~StateMenu()
{
	delete menu;
	delete logo;
}



/***********************************************************************
     * StateMenu
     * update

***********************************************************************/
void ach::StateMenu::update()
{
	menu->controls();
	menu->update();
	stars->update();

	render();
}



/***********************************************************************
     * StateMenu
     * render

***********************************************************************/
void ach::StateMenu::render()
{
	stars->render();
	menu->render();

	rm->draw(logo->spr, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * StateMenu
     * event

***********************************************************************/
void ach::StateMenu::event(sf::Event e)
{
	menu->event(e);
}



/***********************************************************************
     * StateMenu
     * translate

***********************************************************************/
void ach::StateMenu::translate()
{
	menu->translate();
}



/***********************************************************************
     * StateMenu
     * style

***********************************************************************/
void ach::StateMenu::style()
{
	menu->style(&theme->menu);
}



/***********************************************************************
     * StateMenu
     * fill

***********************************************************************/
void ach::StateMenu::fill()
{
	menu->init("Main.Name");

	if (cache->def)
	{
		menu->add("Main.Name"   , new ach::MenuItemFolder  (menu, "Play.Start"          ));
		menu->add("Play.Start"  , new ach::MenuItemAction  (menu, "Play.Normal"         , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Mode", "normal")));
		menu->add("Play.Start"  , new ach::MenuItemAction  (menu, "Play.Hard"           , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Mode", "hard"  )));
	}
	else
	{
		menu->add("Main.Name"   , new ach::MenuItemFolder  (menu, "Play.Name"           ));
		menu->add("Play.Name"   , new ach::MenuItemAction  (menu, "Play.Continue"       , handler_menu_start        , json_pack("{s:b}"    , "New", false)));
		menu->add("Play.Name"   , new ach::MenuItemFolder  (menu, "Play.Start"          ));
		menu->add("Play.Start"  , new ach::MenuItemAction  (menu, "Play.Normal"         , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Mode", "normal")));
		menu->add("Play.Start"  , new ach::MenuItemAction  (menu, "Play.Hard"           , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Mode", "hard"  )));
	}

	menu->add("Main.Name"       , new ach::MenuItemFolder  (menu, "Options.Name"        ));
	menu->add("Main.Name"       , new ach::MenuItemAction  (menu, "Main.Credits"        , handler_common_state      , json_string("credits")));
	menu->add("Main.Name"       , new ach::MenuItemAction  (menu, "Misc.Exit"           , handler_common_state      , json_string("end"    )));

	menu->add("Options.Name"    , new ach::MenuItemFolder  (menu, "Options.Game"        ));
	menu->add("Options.Name"    , new ach::MenuItemFolder  (menu, "Options.Video"       ));
	menu->add("Options.Name"    , new ach::MenuItemFolder  (menu, "Options.Audio"       ));
	menu->add("Options.Name"    , new ach::MenuItemFolder  (menu, "Options.Controls"    ));

	menu->add("Options.Game"    , new ach::MenuItemList    (menu, "Options.Language"    , handler_options_language  , json_object_get_branch(settings->data, "Game"  ), "Language"  , db->listLanguage()   ));
	menu->add("Options.Game"    , new ach::MenuItemList    (menu, "Options.Theme"       , handler_options_theme     , json_object_get_branch(settings->data, "Game"  ), "Theme"     , db->listTheme()      ));
	menu->add("Options.Game"    , new ach::MenuItemCheckbox(menu, "Options.Cutscenes"   , NULL                      , json_object_get_branch(settings->data, "Game"  ), "Cutscenes" ));

	menu->add("Options.Video"   , new ach::MenuItemCheckbox(menu, "Options.Fullscreen"  , handler_options_fullscreen, json_object_get_branch(settings->data, "Window"), "Fullscreen"));
	menu->add("Options.Video"   , new ach::MenuItemCheckbox(menu, "Options.Smooth"      , handler_options_smooth    , json_object_get_branch(settings->data, "Window"), "Smooth"    ));
	menu->add("Options.Video"   , new ach::MenuItemList    (menu, "Options.FrameRate"   , handler_options_framerate , json_object_get_branch(settings->data, "Window"), "FrameRate" , settings->listRates()));

	menu->add("Options.Audio"   , new ach::MenuItemSlider  (menu, "Options.Sound"       , handler_options_audio     , json_object_get_branch(settings->data, "Audio.Sound"), 0, 10));
	menu->add("Options.Audio"   , new ach::MenuItemSlider  (menu, "Options.Music"       , handler_options_audio     , json_object_get_branch(settings->data, "Audio.Music"), 0, 10));

	menu->add("Options.Controls", new ach::MenuItemFolder  (menu, "Options.Keyboard"    ));
	menu->add("Options.Controls", new ach::MenuItemFolder  (menu, "Options.Gamepad"     ));

	for (int i = 0; i < ach::ControlAction::caCount; i++)
	{
		menu->add("Options.Keyboard", new ach::MenuItemControl(menu, (ach::ControlAction)i, true ));
		menu->add("Options.Gamepad" , new ach::MenuItemControl(menu, (ach::ControlAction)i, false));
	}

	menu->add("Options.Keyboard", new ach::MenuItemRebind  (menu, "Options.Redefine"    , true ));
	menu->add("Options.Gamepad" , new ach::MenuItemRebind  (menu, "Options.Redefine"    , false));

	menu->add("Options.Keyboard", new ach::MenuItemAction  (menu, "Options.Reset"       , handler_options_reset     , json_string("Key"    )));
	menu->add("Options.Gamepad" , new ach::MenuItemAction  (menu, "Options.Reset"       , handler_options_reset     , json_string("Joy"    )));

	menu->finalize();
}
