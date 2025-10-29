#include "meta/headers.hpp"


/***********************************************************************
     * StateFinish
     * constructor

***********************************************************************/
ach::StateFinish::StateFinish()
{
	life    = 0.0f;
	anykey  = lm->get("UI.Stats.AnyKey");
	caption = lm->get("UI.Stats.Congratulations");
	text    = new sf::Text();

	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Playtime" ), cache->getPlaytime() ));
	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Deaths"   ), cache->getDeaths()   ));
	lines.push_back(new ach::Statistic(lm->get("UI.Stats.Collected"), cache->getCollected()));

	text->setFont(*theme->credits->font);
	text->setFillColor(theme->credits->color);

	if (cache->difficulty >= ach::Difficulty::gdEasy  ) records->setLeaderboard("Easy"  , cache->playtime);
	if (cache->difficulty >= ach::Difficulty::gdNormal) records->setLeaderboard("Normal", cache->playtime);
	if (cache->difficulty >= ach::Difficulty::gdHard  ) records->setLeaderboard("Hard"  , cache->playtime);

	cache->clear();
	app->mouse(false);
}



/***********************************************************************
     * StateFinish
     * destructor

***********************************************************************/
ach::StateFinish::~StateFinish()
{
	list_delete(lines);
}



/***********************************************************************
     * StateFinish
     * update

***********************************************************************/
void ach::StateFinish::update()
{
	life += tm->get(true);

	stars->update();

	render();
}



/***********************************************************************
     * StateFinish
     * render

***********************************************************************/
void ach::StateFinish::render()
{
	stars->render();

	text->setCharacterSize(theme->credits->size * 2);

	text_draw(text, caption, 0, FINISH_TOP, RENDER_LAYER_GUI_X, ach::TextAlign::taCenter, ach::RenderLayer::rlGUI);

	text->setCharacterSize(theme->credits->size);

	list_foreach(lines)
	{
		if (life < (i + 1) * FINISH_STEP)
			return;

		text_draw(text, lines[i]->caption, FINISH_OFFSET, FINISH_TOP + FINISH_SPACE * (i + 2), RENDER_LAYER_GUI_X - FINISH_OFFSET * 2, ach::TextAlign::taLeft , ach::RenderLayer::rlGUI);
		text_draw(text, lines[i]->value  , FINISH_OFFSET, FINISH_TOP + FINISH_SPACE * (i + 2), RENDER_LAYER_GUI_X - FINISH_OFFSET * 2, ach::TextAlign::taRight, ach::RenderLayer::rlGUI);
	}

	if (life > (lines.size() + 1) * FINISH_STEP)
		text_draw(text, anykey, 0, FINISH_TOP + FINISH_SPACE * (lines.size() + 3), RENDER_LAYER_GUI_X, ach::TextAlign::taCenter, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * StateFinish
     * event

***********************************************************************/
void ach::StateFinish::event(sf::Event e)
{
	if (life < (lines.size() + 1) * FINISH_STEP)
		return;


	switch (e.type)
	{
		case sf::Event::MouseButtonReleased:
		case sf::Event::KeyPressed:
		case sf::Event::JoystickButtonPressed:
			app->stateSet(ach::GameState::gsCredits);

		default:
			break;
	}
}
