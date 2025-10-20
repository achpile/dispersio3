#include "meta/headers.hpp"


/***********************************************************************
     * Records
     * constructor

***********************************************************************/
ach::Records::Records()
{
	data = json_object_get(dm->data, "Records");

	achievements = json_object_get(data, "Achievement");
	highscores   = json_object_get(data, "Highscore"  );
	leaderboards = json_object_get(data, "Time"       );
}



/***********************************************************************
     * Records
     * destructor

***********************************************************************/
ach::Records::~Records()
{
}



/***********************************************************************
     * Records
     * save

***********************************************************************/
void ach::Records::save()
{
	json_dump_file(data, FILE_RECORDS, JSON_INDENT(4) | JSON_SORT_KEYS);
	checksum->store(FILE_RECORDS);
}



/***********************************************************************
     * Records
     * setAchievement

***********************************************************************/
void ach::Records::setAchievement(ach::Achievement achievement)
{
	if (getAchievement(achievement))
		return;

	json_object_set_boolean(achievements, pair_get_string(achievement, pairAchievement), true);
	save();
}



/***********************************************************************
     * Records
     * setHighscore

***********************************************************************/
void ach::Records::setHighscore(ach::ArcadeGame game, int score)
{
	int current = getHighscore(game);

	if (current >= score)
		return;

	json_object_set_integer(highscores, pair_get_string(game, pairArcade), score);
	save();
}



/***********************************************************************
     * Records
     * setLeaderboard

***********************************************************************/
void ach::Records::setLeaderboard(const char *name, float time)
{
	float current = getLeaderboard(name);

	if (current && current <= time)
		return;

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
