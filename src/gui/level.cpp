#include "meta/headers.hpp"


/***********************************************************************
     * LevelSelect
     * constructor

***********************************************************************/
ach::LevelSelect::LevelSelect()
{
	menu     = new ach::Menu(this, callback_level, &theme->menu);
	box      = new ach::RectangleShape();
	preview  = new ach::RectangleShape();
	selected = NULL;

	menu->setPosition(sf::Vector2f(10.0f, RENDER_LAYER_GUI_Y - MENU_LEVEL_HEIGHT - 10.0f));
	menu->setWidthE(MENU_LEVEL_WIDTH);
	menu->setHeightE(MENU_LEVEL_HEIGHT);

	box->setOutlineThickness(MENU_THICKNESS);
	box->setSize(sf::Vector2f(RENDER_LAYER_GUI_X - MENU_LEVEL_WIDTH - 30.0f, MENU_LEVEL_HEIGHT));
	box->setPosition(menu->pos + sf::Vector2f(MENU_LEVEL_WIDTH + 10.0f, 0.0f));

	preview->setOutlineThickness(MENU_THICKNESS);
	preview->setSize(sf::Vector2f(138.0f, 138.0f));
	preview->setPosition(box->getPosition() + sf::Vector2f(20.0f, 20.0f));

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
     * init

***********************************************************************/
void ach::LevelSelect::init(const char *name, ach::Handler handler, ach::LevelList type)
{
	menu->clear();
	menu->init(name);

	fill(name, handler, cache->listLevels(type));

	menu->add(name, new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", NULL, NULL));
	menu->finalize("UI.Menu.Misc.Resume");
}



/***********************************************************************
     * LevelSelect
     * fill

***********************************************************************/
void ach::LevelSelect::fill(const char *name, ach::Handler handler, json_t *list)
{
	json_t *item;
	size_t  index;

	char level[STR_LEN_MENU];

	json_array_foreach(list, index, item)
	{
		snprintf(level, STR_LEN_MENU, "Game.Map.%s.Name", json_string_value(item));

		menu->add(name, new ach::MenuItemAction(menu, level, handler, json_deep_copy(item)));
	}

	json_decref(list);
}
