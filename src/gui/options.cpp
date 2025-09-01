#include "meta/headers.hpp"


/***********************************************************************
     * options_fill

***********************************************************************/
void options_fill(ach::Menu *menu, const char *name)
{
	menu->add(name              , new ach::MenuItemFolder  (menu, "Options.Name"        ));

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
}

