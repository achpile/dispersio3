#include "meta/headers.hpp"


/***********************************************************************
     * Notification
     * constructor

***********************************************************************/
ach::Notification::Notification()
{
	box   = new ach::RectangleShape();
	text  = new sf::Text();

	box->setOutlineThickness(MENU_THICKNESS);
	box->setSize(sf::Vector2f(GUI_NOTIFICATION_X, GUI_NOTIFICATION_Y));

	timer.set(4.0f);
	timer.zero();
}



/***********************************************************************
     * Notification
     * destructor

***********************************************************************/
ach::Notification::~Notification()
{
	delete box;
	delete text;
}



/***********************************************************************
     * Notification
     * update

***********************************************************************/
void ach::Notification::update()
{
	if (!timer.active())
	{
		next();
		return;
	}

	timer.update(true);
	render();
}



/***********************************************************************
     * Notification
     * render

***********************************************************************/
void ach::Notification::render()
{
}



/***********************************************************************
     * Notification
     * style

***********************************************************************/
void ach::Notification::style()
{
	box->style(theme->menu.box);

	text->setCharacterSize(theme->menu.text->size);
	text->setFont(*theme->menu.text->font);
	text->setFillColor(theme->menu.text->color);
}



/***********************************************************************
     * Notification
     * translate

***********************************************************************/
void ach::Notification::translate()
{
	caption = lm->get("UI.Stats.Unlock");
}



/***********************************************************************
     * Notification
     * init

***********************************************************************/
void ach::Notification::init()
{
	sfx = db->getSound(json_object_get_branch_string(dm->data, "Meta.SFX.Achievement"));

	style();
	translate();
}



/***********************************************************************
     * Notification
     * next

***********************************************************************/
void ach::Notification::next()
{
	if (!list.size())
		return;

	spr  = db->getSprite(json_object_getv_branch_string(dm->data, "Meta.GFX.Achievement.%s", pair_get_string(list[0], pairAchievement)))->spr;
	name = lm->getv("UI.Achievement.%s", pair_get_string(list[0], pairAchievement));

	sm->play(sfx->snd);
	list.erase(list.begin());
	timer.reset();
}



/***********************************************************************
     * Notification
     * trigger

***********************************************************************/
void ach::Notification::trigger(ach::Achievement achievement)
{
	list.push_back(achievement);
}
