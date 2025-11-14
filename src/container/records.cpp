#include "meta/headers.hpp"


/***********************************************************************
     * Records
     * constructor

***********************************************************************/
ach::Records::Records()
{
	synced = false;
	data   = json_object_get(dm->data, "Records");

	achievements = json_object_get(data, "Achievement");
	highscores   = json_object_get(data, "Highscore"  );
	leaderboards = json_object_get(data, "Time"       );

	csum();
}



/***********************************************************************
     * Records
     * destructor

***********************************************************************/
ach::Records::~Records()
{
	json_decref(sums);
}



/***********************************************************************
     * Records
     * save

***********************************************************************/
void ach::Records::save()
{
	json_t     *game;
	const char *key;

	json_object_foreach(highscores, key, game)
		if (~(json_integer_value(game)) != json_object_get_integer(sums, key))
			json_integer_set(game, 0);

	json_dump_file(data, FILE_RECORDS, JSON_INDENT(4) | JSON_SORT_KEYS);
	checksum->store(FILE_RECORDS);
}



/***********************************************************************
     * Records
     * init

***********************************************************************/
void ach::Records::init()
{
	json_t *item;
	size_t  index;

	steam->leaderboards.push_back(new ach::Leaderboard("Easy"  , true));
	steam->leaderboards.push_back(new ach::Leaderboard("Normal", true));
	steam->leaderboards.push_back(new ach::Leaderboard("Hard"  , true));

	json_array_foreach(json_object_get_branch(dm->data, "Data.Game.Campaign.MapList"), index, item)
		if (db->getMap(json_string_value(item))->leaderboard)
			steam->leaderboards.push_back(new ach::Leaderboard(json_string_value(item), true));

	for (int i = 0; i < ach::ArcadeGame::agCount; i++)
	{
		if (i == ach::ArcadeGame::agNone)
			continue;

		steam->leaderboards.push_back(new ach::Leaderboard(pair_get_string((ach::ArcadeGame)i, pairArcade), false));
	}

	steam->init();
}



/***********************************************************************
     * Records
     * csum

***********************************************************************/
void ach::Records::csum()
{
	sums = json_object();

	json_t     *game;
	const char *key;

	json_object_foreach(highscores, key, game)
		json_object_set_integer(sums, key, ~(json_integer_value(game)));
}



/***********************************************************************
     * Records
     * sync

***********************************************************************/
void ach::Records::sync()
{
	if (synced)
		return;

	if (!steam->initialized)
		return;

	json_t *item;
	size_t  index;

	bool result = true;

	result &= syncLeaderboard("Easy"  );
	result &= syncLeaderboard("Normal");
	result &= syncLeaderboard("Hard"  );

	json_array_foreach(json_object_get_branch(dm->data, "Data.Game.Campaign.MapList"), index, item)
		if (db->getMap(json_string_value(item))->leaderboard)
			result &= syncLeaderboard(json_string_value(item));

	for (int i = 0; i < ach::ArcadeGame::agCount; i++)
	{
		if (i == ach::ArcadeGame::agNone)
			continue;

		result &= syncHighscore((ach::ArcadeGame)i);
	}

	for (int i = 0; i < ach::Achievement::acCount; i++)
		syncAchievement((ach::Achievement)i);

	if (result)
	{
		synced = true;
		save();
	}
}



/***********************************************************************
     * Records
     * syncAchievement

***********************************************************************/
void ach::Records::syncAchievement(ach::Achievement achievement)
{
	if (getAchievement(achievement))
		steam->setAchievement(pair_get_string(achievement, pairAchievement));
	else if (steam->getAchievement(pair_get_string(achievement, pairAchievement)))
		json_object_set_boolean(achievements, pair_get_string(achievement, pairAchievement), true);
}



/***********************************************************************
     * Records
     * syncLeaderboard

***********************************************************************/
bool ach::Records::syncLeaderboard(const char *name)
{
	ach::Leaderboard *lb = steam->getLeaderboard(name);

	if (!lb)
		return true;

	if (!lb->initialized)
		return false;

	if (lb->synced)
		return true;

	unsigned int score = getLeaderboard(name) * 1000;

	if (score && (!lb->high || score < lb->high))
		lb->setHighscore(score);
	else if (lb->high && (!score || score > lb->high))
		json_object_set_real(leaderboards, name, ((float)lb->high) / 1000.0f);

	lb->synced = true;

	return true;
}



/***********************************************************************
     * Records
     * syncHighscore

***********************************************************************/
bool ach::Records::syncHighscore(ach::ArcadeGame game)
{
	ach::Leaderboard *lb = steam->getLeaderboard(pair_get_string(game, pairArcade));

	if (!lb)
		return true;

	if (!lb->initialized)
		return false;

	if (lb->synced)
		return true;

	unsigned int score = getHighscore(game);

	if (score > lb->high)
		lb->setHighscore(score);
	else if (score < lb->high)
	{
		json_object_set_integer(highscores, pair_get_string(game, pairArcade),  lb->high);
		json_object_set_integer(sums      , pair_get_string(game, pairArcade), ~lb->high);
	}

	lb->synced = true;

	return true;
}



/***********************************************************************
     * Records
     * setAchievement

***********************************************************************/
void ach::Records::setAchievement(ach::Achievement achievement)
{
	if (achievement == ach::Achievement::acCount)
		return;

	if (getAchievement(achievement))
		return;

	notify->trigger(achievement);
	steam->setAchievement(pair_get_string(achievement, pairAchievement));

	json_object_set_boolean(achievements, pair_get_string(achievement, pairAchievement), true);
	save();
}



/***********************************************************************
     * Records
     * setHighscore

***********************************************************************/
void ach::Records::setHighscore(ach::ArcadeGame game, int score)
{
	switch (game)
	{
		case ach::ArcadeGame::agBrickOut: if (score >= 100) setAchievement(ach::Achievement::acBrickOut); break;
		case ach::ArcadeGame::agHexagon : if (score >=  30) setAchievement(ach::Achievement::acHexagon ); break;
		case ach::ArcadeGame::agRace    : if (score >=  50) setAchievement(ach::Achievement::acRace    ); break;
		case ach::ArcadeGame::agSnake   : if (score >=  25) setAchievement(ach::Achievement::acSnake   ); break;
		case ach::ArcadeGame::agSimon   : if (score >=  78) setAchievement(ach::Achievement::acSimon   ); break;
		case ach::ArcadeGame::agTetris  : if (score >=  50) setAchievement(ach::Achievement::acTetris  ); break;

		default: break;
	}


	int current = getHighscore(game);

	if (current >= score)
		return;

	steam->setHighscore(pair_get_string(game, pairArcade), score);
	json_object_set_integer(highscores, pair_get_string(game, pairArcade),  score);
	json_object_set_integer(sums      , pair_get_string(game, pairArcade), ~score);
	save();
}



/***********************************************************************
     * Records
     * setLeaderboard

***********************************************************************/
void ach::Records::setLeaderboard(const char *name, float time)
{
	setAchievement(pair_get_enum(name, pairAchievement));

	float current = getLeaderboard(name);

	if (current && current <= time)
		return;

	steam->setHighscore(name, time * 1000);
	json_object_set_real(leaderboards, name, time);
	save();
}



/***********************************************************************
     * Records
     * getAchievement

***********************************************************************/
bool ach::Records::getAchievement(ach::Achievement achievement)
{
	return json_object_get_boolean(achievements, pair_get_string(achievement, pairAchievement));
}



/***********************************************************************
     * Records
     * getHighscore

***********************************************************************/
int ach::Records::getHighscore(ach::ArcadeGame game)
{
	return json_object_get_integer(highscores, pair_get_string(game, pairArcade));
}



/***********************************************************************
     * Records
     * getLeaderboard

***********************************************************************/
float ach::Records::getLeaderboard(const char *name)
{
	return json_object_get_real(leaderboards, name);
}



/***********************************************************************
     * Records
     * getBestTime

***********************************************************************/
float ach::Records::getBestTime(const char *name)
{
	if (!steam->initialized)
		return 0.0f;

	ach::Leaderboard *lb = steam->getLeaderboard(name);

	if (!lb)
		return 0.0f;

	return (float)lb->best / 1000.0f;
}



/***********************************************************************
     * Records
     * getBestScore

***********************************************************************/
int ach::Records::getBestScore(ach::ArcadeGame game)
{
	if (!steam->initialized)
		return 0;

	ach::Leaderboard *lb = steam->getLeaderboard(pair_get_string(game, pairArcade));

	if (!lb)
		return 0;

	return lb->best;
}



/***********************************************************************
     * Records
     * getRankTime

***********************************************************************/
int ach::Records::getRankTime(const char *name)
{
	if (!steam->initialized)
		return 0;

	ach::Leaderboard *lb = steam->getLeaderboard(name);

	if (!lb)
		return 0;

	return lb->rank;
}



/***********************************************************************
     * Records
     * getRankScore

***********************************************************************/
int ach::Records::getRankScore(ach::ArcadeGame game)
{
	if (!steam->initialized)
		return 0;

	ach::Leaderboard *lb = steam->getLeaderboard(pair_get_string(game, pairArcade));

	if (!lb)
		return 0;

	return lb->rank;
}



/***********************************************************************
     * Records
     * update

***********************************************************************/
bool ach::Records::update(ach::ArcadeGame game)
{
	if (!steam->initialized)
		return true;

	ach::Leaderboard *lb = steam->getLeaderboard(pair_get_string(game, pairArcade));

	if (!lb)
		return true;

	return !lb->hSteamAPICallLoad && !lb->hSteamAPICallBest && !lb->hSteamAPICallHigh;
}
