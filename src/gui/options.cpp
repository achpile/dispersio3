#include "meta/headers.hpp"


/***********************************************************************
     * options_fill

***********************************************************************/
void options_fill(ach::Menu *menu, const char *name)
{
	menu->add(name              , new ach::MenuItemFolder  (menu, "UI.Menu.Options.Name"        ));

	menu->add("UI.Menu.Options.Name"    , new ach::MenuItemFolder  (menu, "UI.Menu.Options.Game"        ));
	menu->add("UI.Menu.Options.Name"    , new ach::MenuItemFolder  (menu, "UI.Menu.Options.Video"       ));
	menu->add("UI.Menu.Options.Name"    , new ach::MenuItemFolder  (menu, "UI.Menu.Options.Audio"       ));
	menu->add("UI.Menu.Options.Name"    , new ach::MenuItemFolder  (menu, "UI.Menu.Options.Controls"    ));

	menu->add("UI.Menu.Options.Game"    , new ach::MenuItemList    (menu, "UI.Menu.Options.Language"    , handler_options_language  , json_object_get_branch(settings->data, "Game"  ), "Language"  , db->listLanguage()   ));
	menu->add("UI.Menu.Options.Game"    , new ach::MenuItemList    (menu, "UI.Menu.Options.Theme"       , handler_options_theme     , json_object_get_branch(settings->data, "Game"  ), "Theme"     , db->listTheme()      ));
	menu->add("UI.Menu.Options.Game"    , new ach::MenuItemCheckbox(menu, "UI.Menu.Options.Timer"       , NULL                      , json_object_get_branch(settings->data, "Game"  ), "Timer"     ));
	menu->add("UI.Menu.Options.Game"    , new ach::MenuItemCheckbox(menu, "UI.Menu.Options.Cutscenes"   , NULL                      , json_object_get_branch(settings->data, "Game"  ), "Cutscenes" ));

	menu->add("UI.Menu.Options.Video"   , new ach::MenuItemCheckbox(menu, "UI.Menu.Options.Fullscreen"  , handler_options_fullscreen, json_object_get_branch(settings->data, "Window"), "Fullscreen"));
	menu->add("UI.Menu.Options.Video"   , new ach::MenuItemCheckbox(menu, "UI.Menu.Options.Smooth"      , handler_options_smooth    , json_object_get_branch(settings->data, "Window"), "Smooth"    ));
	menu->add("UI.Menu.Options.Video"   , new ach::MenuItemList    (menu, "UI.Menu.Options.FrameRate"   , handler_options_framerate , json_object_get_branch(settings->data, "Window"), "FrameRate" , settings->listRates()));

	menu->add("UI.Menu.Options.Audio"   , new ach::MenuItemSlider  (menu, "UI.Menu.Options.Sound"       , handler_options_audio     , json_object_get_branch(settings->data, "Audio.Sound"), 0, 10));
	menu->add("UI.Menu.Options.Audio"   , new ach::MenuItemSlider  (menu, "UI.Menu.Options.Music"       , handler_options_audio     , json_object_get_branch(settings->data, "Audio.Music"), 0, 10));

	menu->add("UI.Menu.Options.Controls", new ach::MenuItemFolder  (menu, "UI.Menu.Options.Keyboard"    ));
	menu->add("UI.Menu.Options.Controls", new ach::MenuItemFolder  (menu, "UI.Menu.Options.Gamepad"     ));

	for (int i = 0; i < ach::ControlAction::caCount; i++)
	{
		menu->add("UI.Menu.Options.Keyboard", new ach::MenuItemControl(menu, (ach::ControlAction)i, true ));
		menu->add("UI.Menu.Options.Gamepad" , new ach::MenuItemControl(menu, (ach::ControlAction)i, false));
	}

	menu->add("UI.Menu.Options.Keyboard", new ach::MenuItemRebind  (menu, "UI.Menu.Options.Redefine"    , handler_options_rebind    , true ));
	menu->add("UI.Menu.Options.Gamepad" , new ach::MenuItemRebind  (menu, "UI.Menu.Options.Redefine"    , handler_options_rebind    , false));

	menu->add("UI.Menu.Options.Keyboard", new ach::MenuItemAction  (menu, "UI.Menu.Options.Reset"       , handler_options_reset     , json_string("Key"    )));
	menu->add("UI.Menu.Options.Gamepad" , new ach::MenuItemAction  (menu, "UI.Menu.Options.Reset"       , handler_options_reset     , json_string("Joy"    )));
}

