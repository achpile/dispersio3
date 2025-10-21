#include "meta/headers.hpp"


/***********************************************************************
     * handler_menu_start

***********************************************************************/
void handler_menu_start(void *, json_t *data)
{
	if (json_object_get_boolean(data, "New"))
		cache->reset(pair_get_enum(json_object_get_string(data, "Difficulty"), pairDifficulty));

	cache->init();

	app->stateSet(ach::GameState::gsGame);
}



/***********************************************************************
     * handler_menu_training

***********************************************************************/
void handler_menu_training(void *context, json_t *)
{
	((ach::StateMenu*)context)->training->init(ach::LevelMode::lmTraining);
	((ach::StateMenu*)context)->state = ach::MenuState::msTraining;
}



/***********************************************************************
     * handler_menu_achievements

***********************************************************************/
void handler_menu_achievements(void *context, json_t *)
{
	((ach::StateMenu*)context)->achievements->init();
	((ach::StateMenu*)context)->state = ach::MenuState::msAchievements;
}



/***********************************************************************
     * handler_menu_leaderboards

***********************************************************************/
void handler_menu_leaderboards(void *context, json_t *)
{
	((ach::StateMenu*)context)->leaderboards->init();
	((ach::StateMenu*)context)->state = ach::MenuState::msLeaderboards;
}



/***********************************************************************
     * handler_menu_pick

***********************************************************************/
void handler_menu_pick(void *, json_t *data)
{
	cache->train(json_object_get_string(data, "Map"));

	app->stateSet(ach::GameState::gsGame);
}
