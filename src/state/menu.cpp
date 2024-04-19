#include "meta/headers.hpp"


/***********************************************************************
     * StateMenu
     * constructor

***********************************************************************/
ach::StateMenu::StateMenu()
{
	menu = new ach::Menu("Main", resources->fonts.menu);

	menu->setPosition(sf::Vector2f(200, 300));
	menu->setWidth(400);
	menu->setHeight(8);
	menu->setSound(resources->sound.blip, resources->sound.back, resources->sound.pick);

	logo = new ach::Sprite(json_object_get_branch_string(dm->data, "Meta.Logo"), false, true);

	logo->spr->setPosition(RENDER_LAYER_GUI_X / 2, logo->tex->getSize().y / 2 + MENU_LOGO_OFFSET);

	fill();
	app->mouse(true);
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
	if (!menu->isActive)
		app->isRunning = false;

	bg->stars->update();
	menu->controls();

	render();

}



/***********************************************************************
     * StateMenu
     * render

***********************************************************************/
void ach::StateMenu::render()
{
	menu->update();

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
     * fill

***********************************************************************/
void ach::StateMenu::fill()
{
	menu->add("Main"   , new ach::MenuItemAction  (menu, "Start"     , handlerState     , json_string("game"   )));
	menu->add("Main"   , new ach::MenuItemFolder  (menu, "Options"   ));
	menu->add("Main"   , new ach::MenuItemAction  (menu, "Credits"   , handlerState     , json_string("credits")));

	menu->add("Options", new ach::MenuItemFolder  (menu, "Game"      ));
	menu->add("Options", new ach::MenuItemFolder  (menu, "Audio"     ));
	menu->add("Options", new ach::MenuItemFolder  (menu, "Controls"  ));

	menu->add("Game"   , new ach::MenuItemList    (menu, "Language"  , handlerLanguage  , json_object_get_branch(settings->data, "Game.Language"), lang->list(), false));
	menu->add("Game"   , new ach::MenuItemCheckbox(menu, "Fullscreen", handlerFullscreen, json_object_get_branch(settings->data, "Window"       ), "Fullscreen"));

	menu->add("Audio"  , new ach::MenuItemSlider  (menu, "Sound"     , handlerAudio     , json_object_get_branch(settings->data, "Audio.Sound"  ), 0, 10));
	menu->add("Audio"  , new ach::MenuItemSlider  (menu, "Music"     , handlerAudio     , json_object_get_branch(settings->data, "Audio.Music"  ), 0, 10));

	menu->finalize();
}
