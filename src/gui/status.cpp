#include "meta/headers.hpp"


/***********************************************************************
     * Status
     * constructor

***********************************************************************/
ach::Status::Status()
{
	width = 500.0f;
	pos   = sf::Vector2f(150.0f, 10.0f);
	box   = new ach::RectangleShape();
	text  = new sf::Text();

	box->setPosition(pos);
	box->setOutlineThickness(MENU_THICKNESS);

	style();
	fill();
}



/***********************************************************************
     * Status
     * destructor

***********************************************************************/
ach::Status::~Status()
{
	list_delete(lines);
	list_delete(items);

	delete text;
	delete box;
}



/***********************************************************************
     * Status
     * update

***********************************************************************/
void ach::Status::update()
{
	list_update(items);
	list_delete(lines);

	if (cache->mode == ach::LevelMode::lmTraining)
	{
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Playtime"      ), cache->getPlaytime() ));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Collected"     ), cache->getItems()    ));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Deaths"        ), cache->getDeaths()   ));
	}
	else
	{
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Playtime"      ), cache->getPlaytime() ));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.CurrentMap"    ), cache->getLeveltime()));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Collected"     ), cache->getCollected()));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.CurrentMap"    ), cache->getItems()    ));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Deaths"        ), cache->getDeaths()   ));
		lines.push_back(new ach::Statistic(""                                , ""));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Cash"          ), cache->getCash()     ));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Item.Misc"     ), ""));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Item.Key"      ), ""));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Item.Freshener"), ""));
		lines.push_back(new ach::Statistic(lm->get("UI.Stats.Item.Game"     ), ""));
	}
}



/***********************************************************************
     * Status
     * render

***********************************************************************/
void ach::Status::render()
{
	rm->draw(box, ach::RenderLayer::rlGUI);

	list_foreach(lines)
	{
		text_draw(text, lines[i]->caption, pos.x + MENU_PADDING * 2, pos.y + MENU_PADDING + spacing * i, width - MENU_PADDING * 4, ach::TextAlign::taLeft , ach::RenderLayer::rlGUI);
		text_draw(text, lines[i]->value  , pos.x + MENU_PADDING * 2, pos.y + MENU_PADDING + spacing * i, width - MENU_PADDING * 4, ach::TextAlign::taRight, ach::RenderLayer::rlGUI);
	}

	if (cache->mode != ach::LevelMode::lmTraining)
		list_foreach(items)
			items[i]->render();
}



/***********************************************************************
     * Status
     * style

***********************************************************************/
void ach::Status::style()
{
	spacing = theme->menu.text->spacing() + MENU_SPACING;

	box->style(theme->menu.box);
	box->setSize(sf::Vector2f(width, 280.0f));

	text->setCharacterSize(theme->menu.text->size);
	text->setFont(*theme->menu.text->font);
	text->setFillColor(theme->menu.text->color);
}



/***********************************************************************
     * Status
     * translate

***********************************************************************/
void ach::Status::translate()
{
	update();
}



/***********************************************************************
     * Status
     * fill

***********************************************************************/
void ach::Status::fill()
{
	int counters[4] = {0, 0, 0, 0};

	list_foreach(db->item)
	{
		items.push_back(new ach::ItemIcon(db->item[i], sf::Vector2f(pos.x + width - MENU_PADDING * 2 - spacing * counters[db->item[i]->category], pos.y - MENU_PADDING / 2 + spacing * (8 + db->item[i]->category))));

		counters[db->item[i]->category]++;
	}
}
