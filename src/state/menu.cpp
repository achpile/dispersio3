#include "meta/headers.hpp"


/***********************************************************************
     * StateMenu
     * constructor

***********************************************************************/
ach::StateMenu::StateMenu()
{
	menu = new ach::Menu(NULL, NULL, &theme->menu);

	menu->setPosition(sf::Vector2f(150, 290));
	menu->setWidthE(500);
	menu->setHeightE(300);

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
	menu->init("UI.Menu.Main.Name");

	if (cache->def)
	{
		menu->add("UI.Menu.Main.Name"   , new ach::MenuItemFolder  (menu, "UI.Menu.Play.Start"          ));
		menu->add("UI.Menu.Play.Start"  , new ach::MenuItemAction  (menu, "UI.Menu.Play.Normal"         , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Mode", "normal")));
		menu->add("UI.Menu.Play.Start"  , new ach::MenuItemAction  (menu, "UI.Menu.Play.Hard"           , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Mode", "hard"  )));
	}
	else
	{
		menu->add("UI.Menu.Main.Name"   , new ach::MenuItemFolder  (menu, "UI.Menu.Play.Name"           ));
		menu->add("UI.Menu.Play.Name"   , new ach::MenuItemAction  (menu, "UI.Menu.Play.Continue"       , handler_menu_start        , json_pack("{s:b}"    , "New", false)));
		menu->add("UI.Menu.Play.Name"   , new ach::MenuItemFolder  (menu, "UI.Menu.Play.Start"          ));
		menu->add("UI.Menu.Play.Start"  , new ach::MenuItemAction  (menu, "UI.Menu.Play.Normal"         , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Mode", "normal")));
		menu->add("UI.Menu.Play.Start"  , new ach::MenuItemAction  (menu, "UI.Menu.Play.Hard"           , handler_menu_start        , json_pack("{s:b,s:s}", "New", true, "Mode", "hard"  )));
	}

	options_fill(menu, "UI.Menu.Main.Name");

	menu->add("UI.Menu.Main.Name"       , new ach::MenuItemAction  (menu, "UI.Menu.Main.Credits"        , handler_common_state      , json_string("credits")));
	menu->add("UI.Menu.Main.Name"       , new ach::MenuItemAction  (menu, "UI.Menu.Misc.Exit"           , handler_common_state      , json_string("end"    )));

	menu->finalize(NULL);
}
