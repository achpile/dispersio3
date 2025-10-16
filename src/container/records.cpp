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
void ach::Records::setAchievement(const char *name)
{
	bool current = getAchievement(name);

	if (current)
		return;

	json_object_set_boolean(achievements, name, true);
	save();
}



/***********************************************************************
     * Records
     * setHighscore

***********************************************************************/
void ach::Records::setHighscore(const char *name, int score)
{
	int current = getHighscore(name);

	if (current >= score)
		return;

	json_object_set_integer(highscores, name, score);
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
bool ach::Records::getAchievement(const char *name)
{
	return json_object_get_boolean(achievements, name);
}



/***********************************************************************
     * Records
     * getHighscore

***********************************************************************/
int ach::Records::getHighscore(const char *name)
{
	return json_object_get_integer(highscores, name);
}



/***********************************************************************
     * Records
     * getLeaderboard

***********************************************************************/
float ach::Records::getLeaderboard(const char *name)
{
	return json_object_get_real(leaderboards, name);
}
