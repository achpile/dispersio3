#include "meta/headers.hpp"


/***********************************************************************
     * Achievements
     * constructor

***********************************************************************/
ach::Achievements::Achievements()
{
	active = false;
}



/***********************************************************************
     * Achievements
     * destructor

***********************************************************************/
ach::Achievements::~Achievements()
{
}



/***********************************************************************
     * Achievements
     * update

***********************************************************************/
void ach::Achievements::update()
{
}



/***********************************************************************
     * Achievements
     * render

***********************************************************************/
void ach::Achievements::render()
{
}



/***********************************************************************
     * Achievements
     * event

***********************************************************************/
void ach::Achievements::event(sf::Event)
{
}



/***********************************************************************
     * Achievements
     * translate

***********************************************************************/
void ach::Achievements::translate()
{
}



/***********************************************************************
     * Achievements
     * style

***********************************************************************/
void ach::Achievements::style()
{
}



/***********************************************************************
     * Achievements
     * controls

***********************************************************************/
void ach::Achievements::controls()
{
}



/***********************************************************************
     * Achievements
     * init

***********************************************************************/
void ach::Achievements::init()
{
	const char *name;

	for (int i = 0; i < ach::Achievement::acCount; i++)
	{
		name = pair_get_string((ach::Achievement)i, pairAchievement);

		data[i].spr  = db->getSprite(json_object_getv_branch_string(dm->data, "Meta.GFX.Achievement.%s", name))->spr->spr;
		data[i].name = lm->getv("UI.Achievement.%s.Name"       , name);
		data[i].desc = lm->getv("UI.Achievement.%s.Description", name);

		if (!records->getAchievement((ach::Achievement)i))
			data[i].spr = db->getSprite(json_object_get_branch_string(dm->data, "Meta.GFX.Achievement.Locked"))->spr->spr;
	}

	active = true;
}
