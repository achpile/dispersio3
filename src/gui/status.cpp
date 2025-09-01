#include "meta/headers.hpp"


/***********************************************************************
     * Status
     * constructor

***********************************************************************/
ach::Status::Status()
{
	width = 500.0f;
	pos   = sf::Vector2f(150.0f, 20.0f);
	box   = new ach::RectangleShape();
	text  = new sf::Text();

	box->setPosition(pos);
	box->setOutlineThickness(MENU_THICKNESS);

	style();
}



/***********************************************************************
     * Status
     * destructor

***********************************************************************/
ach::Status::~Status()
{
	list_delete(lines);

	delete text;
	delete box;
}



/***********************************************************************
     * Status
     * update

***********************************************************************/
void ach::Status::update()
{
	list_delete(lines);

	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Playtime"      ), cache->getPlaytime() ));
	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Deaths"        ), cache->getDeaths()   ));
	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Collected"     ), cache->getCollected()));
	lines.push_back(new ach::Statistic(lm->get("UI.Stats.CollectedMap"  ), cache->getItems()    ));
	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Item.Misc"     ), ""));
	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Item.Key"      ), ""));
	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Item.Freshener"), ""));
	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Item.Game"     ), ""));
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
		text_draw(text, lines[i]->caption, pos.x + MENU_PADDING, pos.y + MENU_PADDING + spacing * i, width - MENU_PADDING * 2, ach::TextAlign::taLeft , ach::RenderLayer::rlGUI);
		text_draw(text, lines[i]->value  , pos.x + MENU_PADDING, pos.y + MENU_PADDING + spacing * i, width - MENU_PADDING * 2, ach::TextAlign::taRight, ach::RenderLayer::rlGUI);
	}
}



/***********************************************************************
     * Status
     * style

***********************************************************************/
void ach::Status::style()
{
	spacing = theme->menu.spacing + MENU_SPACING;

	box->style(&theme->menu);
	box->setSize(sf::Vector2f(width, 240.0f));

	text->setCharacterSize(theme->menu.size);
	text->setFont(*theme->menu.font);
	text->setFillColor(theme->menu.color);
}



/***********************************************************************
     * Status
     * translate

***********************************************************************/
void ach::Status::translate()
{
	update();
}
