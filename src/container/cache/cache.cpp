#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * constructor

***********************************************************************/
ach::Cache::Cache()
{
	current  = NULL;
	process  = NULL;
	finished = false;
	text     = new sf::Text();

	campaign = json_object_get_branch(dm->data, "Data.Game.Campaign");
	cache    = json_object_get_branch(dm->data, "Data.Game.Cache");

	text->setPosition(5.0f, 5.0f);
	text->setOutlineThickness(3.0f);
}



/***********************************************************************
     * Cache
     * destructor

***********************************************************************/
ach::Cache::~Cache()
{
	delete text;
}



/***********************************************************************
     * Cache
     * update

***********************************************************************/
void ach::Cache::update()
{
	playtime  += tm->get();
	leveltime += tm->get();
}



/***********************************************************************
     * Cache
     * render

***********************************************************************/
void ach::Cache::render()
{
	if (mode != ach::LevelMode::lmTraining && !settings->isTimer())
		return;

	text->setString(getPlaytime());

	rm->draw(text, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * Cache
     * style

***********************************************************************/
void ach::Cache::style()
{
	sf::Color c = theme->menu.text->color;

	text->setCharacterSize(theme->menu.text->size);
	text->setFont(*theme->menu.text->font);
	text->setFillColor(c);
	text->setOutlineColor(sf::Color(255 - c.r, 255 - c.g, 255 - c.b));
}
