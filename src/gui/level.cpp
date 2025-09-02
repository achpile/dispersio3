#include "meta/headers.hpp"


/***********************************************************************
     * LevelSelect
     * constructor

***********************************************************************/
ach::LevelSelect::LevelSelect(void *_context, ach::Handler _handler)
{
	menu     = new ach::Menu(this, callback_level, &theme->menu);
	text     = new ach::Text(&theme->menu);
	box      = new ach::RectangleShape();
	preview  = new ach::RectangleShape();

	selected = NULL;
	active   = false;
	context  = _context;
	handler  = _handler;

	menu->setPosition(sf::Vector2f(10.0f, RENDER_LAYER_GUI_Y - MENU_LEVEL_HEIGHT - 10.0f));
	menu->setWidthE(MENU_LEVEL_WIDTH);
	menu->setHeightE(MENU_LEVEL_HEIGHT);

	box->setOutlineThickness(MENU_THICKNESS);
	box->setSize(sf::Vector2f(RENDER_LAYER_GUI_X - MENU_LEVEL_WIDTH - 30.0f, MENU_LEVEL_HEIGHT));
	box->setPosition(menu->pos + sf::Vector2f(MENU_LEVEL_WIDTH + 10.0f, 0.0f));

	preview->setOutlineThickness(MENU_THICKNESS);
	preview->setSize(sf::Vector2f(138.0f, 138.0f));
	preview->setPosition(box->getPosition() + sf::Vector2f(20.0f, 20.0f));

	text->setPosition(preview->getPosition() + sf::Vector2f(0.0f, 158.0f));
	text->setWidth(RENDER_LAYER_GUI_X - MENU_LEVEL_WIDTH - 70.0f);

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
	delete text;
}



/***********************************************************************
     * LevelSelect
     * update

***********************************************************************/
void ach::LevelSelect::update()
{
	if (selected)
	{
		selected->preview->spr->setPosition(preview->getPosition() + sf::Vector2f(5.0f, 5.0f));
		text->setString(lm->getv("Game.Map.%s.Description", selected->name));
	}
}



/***********************************************************************
     * LevelSelect
     * render

***********************************************************************/
void ach::LevelSelect::render()
{
	menu->render();

	rm->draw(box    , ach::RenderLayer::rlGUI);

	if (selected)
	{
		rm->draw(preview               , ach::RenderLayer::rlGUI);
		rm->draw(selected->preview->spr, ach::RenderLayer::rlGUI);

		text->render();
	}
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
	text->style(&theme->menu);
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
	menu->update();
}



/***********************************************************************
     * LevelSelect
     * pick

***********************************************************************/
void ach::LevelSelect::pick(json_t *data)
{
	if (handler)
		handler(context, data);
}



/***********************************************************************
     * LevelSelect
     * init

***********************************************************************/
void ach::LevelSelect::init(ach::LevelMode type)
{
	active = true;

	const char *name = pair_get_string(type, pairLevelModeMenu);

	menu->clear();
	menu->init(name);

	fill(type, name, cache->listLevels(type));

	menu->add(name, new ach::MenuItemAction(menu, "UI.Menu.Misc.Resume", handler_level_resume, NULL));
	menu->finalize(NULL);
}



/***********************************************************************
     * LevelSelect
     * fill

***********************************************************************/
void ach::LevelSelect::fill(ach::LevelMode type, const char *name, json_t *list)
{
	json_t *item;
	size_t  index;

	char level[STR_LEN_MENU];

	json_array_foreach(list, index, item)
	{
		snprintf(level, STR_LEN_MENU, "Game.Map.%s.Name", json_string_value(item));

		menu->add(name, new ach::MenuItemAction(menu, level, handler_level_pick, json_pack("{s:s,s:s}", "Map", json_string_value(item), "Origin", pair_get_string(type, pairLevelMode))));
	}

	json_decref(list);
}
