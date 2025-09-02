#include "meta/headers.hpp"


/***********************************************************************
     * LevelSelect
     * constructor

***********************************************************************/
ach::LevelSelect::LevelSelect()
{
	menu    = new ach::Menu(this, &theme->menu);
	box     = new ach::RectangleShape();
	preview = new ach::RectangleShape();

	menu->setPosition(sf::Vector2f(10.0f, 160.0f));
	menu->setWidthE(250.0f);
	menu->setHeightE(430.0f);

	box->setOutlineThickness(MENU_THICKNESS);
	box->setSize(sf::Vector2f(520.0f, 430.0f));
	box->setPosition(sf::Vector2f(270.0f, 160.0f));

	preview->setOutlineThickness(MENU_THICKNESS);
	preview->setSize(sf::Vector2f(138.0f, 138.0f));
	preview->setPosition(sf::Vector2f(290.0f, 180.0f));

	fill();
	style();
}



/***********************************************************************
     * LevelSelect
     * destructor

***********************************************************************/
ach::LevelSelect::~LevelSelect()
{
	delete menu;
	delete box;
	delete preview;
}



/***********************************************************************
     * LevelSelect
     * update

***********************************************************************/
void ach::LevelSelect::update()
{
}



/***********************************************************************
     * LevelSelect
     * render

***********************************************************************/
void ach::LevelSelect::render()
{
	menu->update();
	menu->render();

	rm->draw(box    , ach::RenderLayer::rlGUI);
	rm->draw(preview, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * LevelSelect
     * event

***********************************************************************/
void ach::LevelSelect::event(sf::Event e)
{
	menu->event(e);
}



/***********************************************************************
     * LevelSelect
     * style

***********************************************************************/
void ach::LevelSelect::style()
{
	menu->style(&theme->menu);
	box->style(&theme->menu);
	preview->style(&theme->menu);
}



/***********************************************************************
     * LevelSelect
     * translate

***********************************************************************/
void ach::LevelSelect::translate()
{
	menu->translate();
}



/***********************************************************************
     * LevelSelect
     * controls

***********************************************************************/
void ach::LevelSelect::controls()
{
	menu->controls();
}



/***********************************************************************
     * LevelSelect
     * fill

***********************************************************************/
void ach::LevelSelect::fill()
{
	menu->init("UI.Menu.Main.InGame");

	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));
	menu->add("UI.Menu.Main.InGame", new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL , NULL));

	menu->finalize("UI.Menu.Misc.Resume");
}
