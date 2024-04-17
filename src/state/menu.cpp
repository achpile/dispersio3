#include "meta/headers.hpp"


/***********************************************************************
     * StateMenu
     * constructor

***********************************************************************/
ach::StateMenu::StateMenu()
{
	menu = new ach::Menu("Main");

	menu->setPosition(sf::Vector2f(100.0f, 100.0f));
	menu->setWidth(400.0f);
	menu->setHeight(6);

	fill();
}



/***********************************************************************
     * StateMenu
     * destructor

***********************************************************************/
ach::StateMenu::~StateMenu()
{
	delete menu;
}



/***********************************************************************
     * StateMenu
     * update

***********************************************************************/
void ach::StateMenu::update()
{
	if (!menu->isActive)
		app->isRunning = false;

	render();

	menu->controls();
	menu->update();
}



/***********************************************************************
     * StateMenu
     * render

***********************************************************************/
void ach::StateMenu::render()
{
	bg->stars->update();
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
     * fill

***********************************************************************/
void ach::StateMenu::fill()
{
	menu->add("Main"   , new ach::MenuItemFolder  (menu, "Start"     ));
	menu->add("Main"   , new ach::MenuItemFolder  (menu, "Options"   ));
	menu->add("Main"   , new ach::MenuItemAction  (menu, "Credits"   ));

	menu->add("Options", new ach::MenuItemFolder  (menu, "Game"      ));
	menu->add("Options", new ach::MenuItemFolder  (menu, "Video"     ));
	menu->add("Options", new ach::MenuItemFolder  (menu, "Audio"     ));
	menu->add("Options", new ach::MenuItemFolder  (menu, "Controls"  ));

	menu->add("Game"   , new ach::MenuItemList    (menu, "Language"  , handlerLanguage, json_object_get_branch(settings->data, "Game.Language"), lang->list(), false));

	menu->add("Audio"  , new ach::MenuItemSlider  (menu, "Sound"     , NULL, json_object_get_branch(settings->data, "Audio.Sound"  ), 0, 10));
	menu->add("Audio"  , new ach::MenuItemSlider  (menu, "Music"     , NULL, json_object_get_branch(settings->data, "Audio.Music"  ), 0, 10));

	menu->add("Video"  , new ach::MenuItemCheckbox(menu, "Fullscreen", NULL, json_object_get_branch(settings->data, "Window"       ), "Fullscreen"));
	menu->add("Video"  , new ach::MenuItemCheckbox(menu, "Aspect"    , NULL, json_object_get_branch(settings->data, "Video"        ), "Aspect"    ));
	menu->add("Video"  , new ach::MenuItemCheckbox(menu, "Smooth"    , NULL, json_object_get_branch(settings->data, "Video"        ), "Smooth"    ));

	menu->finalize();
}
